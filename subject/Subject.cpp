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
    std::cin >> name_sub;
    name_sub = split_string(name_sub);
    name_subject = name_sub;
    Mark n;
    mark_subj.push_back(n);
    type_subject = n.return_type();
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

void Subject::print_subject_mark() {
    if(type_subject == "Диф. зачёт") {
       std::cout << "Ваша оценка за предмет: " << mark_subj[0].return_mark() << std::endl;
    } else if(type_subject == "Зачёт") {
        if(mark_subj[0].return_mark() == 1) {
            std::cout << "Ваша оценка за предмет: Зачёт" << std::endl;
        } else if(mark_subj[0].return_mark() == 0) {
            std::cout << "Ваша оценка за предмет: Не зачёт" << std::endl;
        }
    } else {
        std::cout << "У предмета отстутствует тип оценки" << std::endl;
    }
}

void Subject::change_mark(){
    mark_subj[0].change_mark();
}

void Subject::print_hour() {
    std::cout << "Часы за предмет: " << hour_subject << std::endl;
}

void Subject::add_task() {
    int type = -1;
    std::string name;

    std::cout << "Виды работ:" << std::endl;
    std::cout << "1. Лабораторная" << std::endl << "2. РГЗ" << std::endl << "3. Курсовая работа" << std::endl
    <<"4. Тест" << std::endl  << "5. Экзамен" << std::endl;
    std::cout << "Выберите тип задания:";

    try {
        std::cin >> type;
    }catch (int a){
        std::cout << "Вы ввели не число. Передмет не добавлен." << std::endl;
        return;
    }

    std::cout << "Название работы: ";
    std::cin >> name;
    name = split_string(name);

    switch(type - 1) {
        case 0: {
            Concrete_Lab_work* Lab_work = new Concrete_Lab_work();
            tasks.push_back(Lab_work->create_subject());
            tasks[tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 1: {
            Tasks_cereator* Rgz = new Concrete_Rgz();
            tasks.push_back(Rgz->create_subject());
            tasks[tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 2: {
            Tasks_cereator* Coursework = new Concrete_Coursework();
            tasks.push_back(Coursework->create_subject());
            tasks[tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 3: {
            Tasks_cereator* Test = new Concrete_Test();
            tasks.push_back(Test->create_subject());
            tasks[tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 4: {
            Tasks_cereator* Exam = new Concrete_Exam();
            tasks.push_back(Exam->create_subject());
            tasks[tasks.size() - 1]->set_name_work(name);
            break;
        }
        default: {
            std::cout << "Такой вариант отсутствует." << std::endl;
            break;
        }
    }
}

std::string Subject::get_name_subject() {
    return name_subject;
}

Subject::~Subject() = default;

std::string Subject::get_type_subject() {
    return type_subject;
}

void Subject::print_task_name() {
    std::cout << "Список заданий по предмету: " << std::endl;
    for(int i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i]->get_name_work() << std::endl;
    }
}

void Subject::delete_task() {
    print_task_list();
    std::cout << "Какое задание желаете удалить из предмета? ";
    std::cout << "Введите индекс элемента: ";
    int index;
    std::cin >> index;
    tasks.erase(tasks.begin() + index - 1);
}

void Subject::print_task_list() {
    std::cout << "Список заданий по предмету: " << std::endl;
    for(int i = 0; i < tasks.size(); i++) {
        if(tasks[i]->get_mark().return_type() == "Экзамен") {
            if(tasks[i]->get_mark().return_mark() == 1) {
                std::cout << i + 1 << ". " << tasks[i]->get_name_work()  << " " << tasks[i]->get_type_task()
                        << "Зачёт" << std::endl;
            } else {
                std::cout << i + 1 << ". " << tasks[i]->get_name_work()  << " " << tasks[i]->get_type_task()
                          << "Не зачёт" << std::endl;
            }
        } else {
            std::cout << i + 1 << ". " << tasks[i]->get_name_work()  << " " << tasks[i]->get_type_task()
            << tasks[i]->get_mark().return_mark() << std::endl;
        }
    }
}

bool Subject::its_subj() {
    for(int i = 0; i < tasks.size(); i++) {
        if(tasks[i]->get_type_task() == "Экзамен")
            return true;
    }
    return false;
}

void Subject::task_change_mark() {
    print_task_list();
    int index;
    std::cout << "Оценку за какой предмет вы хотите выставыить?" << std::endl << "Ввод: ";
    std::cin >> index;
    tasks[index - 1]->change_mark();
}

bool Subject::subj_delivered() {
    if (type_subject == "Диф. зачёт") {
        if (mark_subj[0].return_mark() > 3) {
            return true;
        }
    } else if (type_subject == "Зачёт") {
        if (mark_subj[0].return_mark() == 1) {
            return true;
        }
    } else {
        return false;
    }
    return false;
}

void Subject::print_task_delivered() {
    int j = 1;
    for(int i = 0; i < tasks.size(); i++) {
        if(tasks[i]->get_mark().return_type() == "Диф. зачёт") {
            if(tasks[i]->get_mark().return_mark() < 3)
                std::cout << j++ << " " << tasks[i]->get_name_work() << " " << tasks[i]->get_type_task()<< std::endl;
        } else if(tasks[i]->get_mark().return_type() == "Зачёт") {
            if(tasks[i]->get_mark().return_mark() != 1)
                std::cout << j++ << " " << tasks[i]->get_name_work() << " " << tasks[i]->get_type_task()<< std::endl;
        }
        if(j == 1)
            std::cout << "У данного нет не сданных заданий" << std::endl;
    }
}
