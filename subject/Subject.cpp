#include "Subject.h"

std::string split_string(std::string input_string) {
    std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    input_string.erase(
            input_string.begin(),
            find_if(input_string.begin(), input_string.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return input_string;
}


Subject::Subject() {
    std::string name_sub;
    std::cout << "Введите название предмета: ";
    getline(std::cin, name_sub);
    name_sub = split_string(name_sub);
    name_subject = name_sub;

    std::cout << "Выберите тип оценки: " << std::endl;
    std::cout << "1. Зачёт" << std::endl;
    std::cout << "2. Дифференцированный зачёт/Экзамен" << std::endl;
    std::cout << "Ввод: ";
    int select = 0;
    try {
        std::cin >> select;
        if((select != 1) && (select != 2))
            throw;
    } catch(int a) {
        std::cout << "Выбрано значение в не диапазона. Предмет небыл добавлен." << std::endl;
        return ;
    }

    if(select == 1) {
        type_subject = "Bool";
        mark = new Bool_mark();
    } else {
        type_subject = "Int";
        mark = new Int_mark();

      /*  auto *m = dynamic_cast<Int_mark*>(mark);

        if (m)
            m->print_mark(); */
    }
}

Subject::Subject(std::string name_sub, int i_new_mark) {
    name_sub = split_string(name_sub);
    name_subject = name_sub;
    try {
        if((i_new_mark < 1) || (i_new_mark > 5))
            throw;
        else {
            type_subject = "Int";
            mark = new Int_mark(i_new_mark);
        }
    } catch (int a) {
        std::cout << "Выход из диапазона возможных оценок. Значение было задано по умолчанию." << std::endl;
        type_subject = "Int";
        mark = new Int_mark(1);
    }
}

Subject::Subject(std::string name_sub, bool bmark) {
    name_sub = split_string(name_sub);
    name_subject = name_sub;
    type_subject = "Bool";
    Bool_mark new_markq(bmark);
   // mark = &new_markq;
}

void Subject::add_hour(unsigned hours = -1) {
    if(hours  == -1) {
        std::cout << "Общее количество часов?" << std::endl;
        std::cout << "Ввод: ";
        std::string hours;
        getline(std::cin.ignore(), hours);
        hours = split_string(hours);
        try {
            hour_subject = stoi(hours);
        } catch (int a) {
            std::cout << "Вы ввели не число" << std::endl;
            std::cout << "Число было задано по стандарту" << std::endl;
            hour_subject = 0;
            return;
        }

        if (hour_subject < 0) {
            std::cout << "Число меньше 0" << std::endl;
            std::cout << "Число было задано по стандарту" << std::endl;
            hour_subject = 0;
            return;
        }
    } else {
        hour_subject = hours;
    }
}

void Subject::rename_subj(const std::string& new_name) {
    if(new_name  == " ") {
        std::cout << "Переименовать предмет ?" << std::endl;
        std::cout << "Ввод: ";
        std::string str;
        getline(std::cin.ignore(), str);
        str = split_string(str);
        name_subject = str;
    } else {
        name_subject = new_name;
    }
}

void Subject::print_name_subject() const {
    std::cout << "Предмет: " << name_subject << std::endl;
}

void Subject::print_subject_mark() const {
    if(type_subject == "Int") {
        auto m = dynamic_cast<Int_mark*>(mark);
        m->print_mark();
    } else if(type_subject == "Bool") {
        auto m = dynamic_cast<Bool_mark*>(mark);
        m->print_mark();
    } else {
        std::cout << "У предмета отстутствует тип оценки" << std::endl;
    }
}

void Subject::change_mark(unsigned new_mark = 0) {
    if(new_mark == 0) {
        std::cout << "Введите новую оценку..." << std::endl;
        mark = new Int_mark();
    } else if((new_mark < 1) || (new_mark > 5)) {
        std::cout << "Вы вышли из разрешонного диапазона." << std::endl;
    } else {
        mark = new Int_mark(int(new_mark));
    }
}

void Subject::change_mark(bool new_mark) {
    if(new_mark) {
        mark = new Bool_mark(new_mark);
    }
}

Subject::~Subject() {
    delete mark;
}

void Subject::print_hour() {
    std::cout << "Часы за предмет: " << hour_subject << std::endl;
}


void Subject::add_task() {
    int type = -1;
    std::string name;

    std::cout << "Виды работ:" << std::endl;
    std::cout << "1. Лабораторная\n2. РГЗ\n 3. Курсовая работа\n 4. Тест\n 5." << std::endl;
    std::cout << "Выберите тип задания:";

    try {
        std::cin >> type;
    }catch (int a){
        std::cout << "Вы ввели не число. Передмет не добавлен." << std::endl;
        return;
    }

    std::cout << "Название работы: ";
    getline(std::cin, name);
    name = split_string(name);

    switch(type - 1) {
        case 0: {
            Concrete_Lab_work* Lab_work = new Concrete_Lab_work();
            tasks.push_back(Lab_work->create_subject());
            tasks[tasks.size()]->set_name_work(name);
            Mark *new_mark = new Int_mark();
            tasks[tasks.size()]->set_mark(new_mark);
            break;
        }
        case 1: {
            Tasks_cereator* Rgz = new Concrete_Rgz();
            tasks.push_back(Rgz->create_subject());
            tasks[tasks.size()]->set_name_work(name);
            Mark *new_mark = new Int_mark();
            tasks[tasks.size()]->set_mark(new_mark);
            break;
        }
        case 2: {
            Tasks_cereator* Coursework = new Concrete_Coursework();
            tasks.push_back(Coursework->create_subject());
            tasks[tasks.size()]->set_name_work(name);
            Mark *new_mark = new Int_mark();
            tasks[tasks.size()]->set_mark(new_mark);
            break;
        }
        case 3: {
            Tasks_cereator* Test = new Concrete_Test();
            tasks.push_back(Test->create_subject());
            tasks[tasks.size()]->set_name_work(name);
            Mark *new_mark = new Int_mark();
            tasks[tasks.size()]->set_mark(new_mark);
            break;
        }
        case 4: {
            Tasks_cereator* Exam = new Concrete_Exam();
            tasks.push_back(Exam->create_subject());
            tasks[tasks.size()]->set_name_work(name);
            Mark *new_mark = new Int_mark();
            tasks[tasks.size()]->set_mark(new_mark);
            break;
        }
        default: {
            std::cout << "Такой вариант отсутствует." << std::endl;
            break;
        }
    }
}
