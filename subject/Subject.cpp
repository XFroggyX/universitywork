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

void Subject::change_mark(){
    mark_subj[0].change_mark();
    for(auto & list_task : list_tasks) {
        if(list_task->get_type_task() == "Экзамен") {
            list_task->get_mark().set_mark(mark_subj[0].return_mark());
        }
    }
}

void Subject::add_task() {
    int type = -1;
    std::string name;

    std::cout << "Виды работ:" << std::endl;
    std::cout << "1. Лабораторная" << std::endl << "2. РГЗ" << std::endl << "3. Курсовая работа" << std::endl
    <<"4. Тест" << std::endl  << "5. Экзамен" << std::endl;
    std::cout << "Выберите тип задания: ";

    try {
        std::cin >> type;
    }catch (...){
        std::cout << "Вы ввели не число. Передмет не добавлен." << std::endl;
        return;
    }

    std::cout << "Название работы: ";
    std::cin >> name;
    name = split_string(name);

    switch(type - 1) {
        case 0: {
            auto* Lab_work = new Concrete_Lab_work();
            list_tasks.push_back(Lab_work->create_subject());
            list_tasks[list_tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 1: {
            auto* Rgz = new Concrete_Rgz();
            list_tasks.push_back(Rgz->create_subject());
            list_tasks[list_tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 2: {
            auto* Coursework = new Concrete_Coursework();
            list_tasks.push_back(Coursework->create_subject());
            list_tasks[list_tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 3: {
            auto* Test = new Concrete_Test();
            list_tasks.push_back(Test->create_subject());
            list_tasks[list_tasks.size() - 1]->set_name_work(name);
            break;
        }
        case 4: {
            auto* Exam = new Concrete_Exam();
            list_tasks.push_back(Exam->create_subject());
            list_tasks[list_tasks.size() - 1]->set_name_work(name);
            mark_subj[0].change_type_int();
            type_subject = mark_subj[0].return_type();
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

void Subject::delete_task() {
    print_task_list();
    std::cout << "Какое задание желаете удалить из предмета? " << std::endl;
    std::cout << "Введите индекс задания: ";
    int index;
    std::cin >> index;
    list_tasks.erase(list_tasks.begin() + index - 1);
}

void Subject::print_task_list() {
    std::cout << "Список заданий по предмету: " << std::endl;
    for(int i = 0; i < list_tasks.size(); i++) {
        if(list_tasks[i]->get_mark().return_type() == "Экзамен") {
            if(list_tasks[i]->get_mark().return_mark() == 1) {
                std::cout << i + 1 << ". " << list_tasks[i]->get_name_work() << " " << list_tasks[i]->get_type_task()
                          << " Зачёт" << std::endl;
            } else {
                std::cout << i + 1 << ". " << list_tasks[i]->get_name_work() << " " << list_tasks[i]->get_type_task()
                          << " Не зачёт" << std::endl;
            }
        } else {
            std::cout << i + 1 << ". " << list_tasks[i]->get_name_work() << " " << list_tasks[i]->get_type_task()
                      <<  " " << list_tasks[i]->get_mark().return_mark() << std::endl;
        }
    }
}

bool Subject::its_ex() {
    for(auto & list_task : list_tasks) {
        if(list_task->get_type_task() == "Экзамен")
            return true;
    }
    return false;
}

void Subject::task_change_mark(bool status) {
    print_task_list();
    int index;
    std::cout << "Оценку за какой предмет вы хотите выставыить?" << std::endl << "Ввод: ";
    std::cin >> index;
    if((list_tasks[index - 1]->get_type_task() == "Экзамен") && (status)) {
        list_tasks[index - 1]->change_mark();
        mark_subj.clear();
        mark_subj.push_back(list_tasks[index - 1]->get_mark());
    }
    else if(list_tasks[index - 1]->get_type_task() != "Экзамен")
        list_tasks[index - 1]->change_mark();
    else
        std::cout << "У студента отстутствует допуск к экзамену." << std::endl;
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
    for(auto & list_task : list_tasks) {
        if(list_task->get_mark().return_type() == "Диф. зачёт") {
            if(list_task->get_mark().return_mark() < 3)
                std::cout << j++ << " " << list_task->get_name_work() << " " << list_task->get_type_task() << std::endl;
        } else if(list_task->get_mark().return_type() == "Зачёт") {
            if(list_task->get_mark().return_mark() != 1)
                std::cout << j++ << " " << list_task->get_name_work() << " " << list_task->get_type_task() << std::endl;
        }
        if(j == 1)
            std::cout << "У данного нет не сданных заданий" << std::endl;
    }
}

std::string Subject::get_mark() {
    if(mark_subj[0].return_type() == "Зачёт") {
        if(mark_subj[0].return_mark() == 1)
            return "Зачёт";
        else
            return "Не зачёт";
    } else {
        return std::to_string(mark_subj[0].return_mark());
    }

}
