#include "System.h"

std::string sysstr(std::string input_string) {
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

void System::add_university() {
    University un;
    list_university.push_back(un);
    std::cout << "-- ВУЗ успешно добавлен --" << std::endl;
}

void System::print_university() {
    std::cout << "Список ВУЗов: " << std::endl;
    for(int i = 0; i < list_university.size(); i++) {
        std::cout << i + 1  << " " << list_university[i].get_name_university() << std::endl;
    }
}

void System::delete_university() {
    print_university();
    std::string swap;
    std::cout << std::endl << "____________________________" << std::endl;
    std::cout << "Введите номер ВУЗа:";
    int index = 0;
    try {
        std::cin >> swap;
        index = stoi(swap);

        if((index > list_university.size()) || (index < 0))
            throw std::exception();

    } catch (...){
        std::cout << "Институт с таким номером отсутствует." << std::endl;
        return;
    }
    list_university.erase(list_university.begin() + index - 1);
    std::cout << "-- ВУЗ успешно удалён --" << std::endl;
}

void System::work_with_session(int u_index, int g_index, int s_index) {
    while(true) {
        int select;
        int q = -1;
        std::string swap;

        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - список экзаменов" << std::endl;
        std::cout << "2 - список зачётов" << std::endl;
        std::cout << "3 - долги по предметам" << std::endl;
        std::cout << "4 - полная информация по сессии" << std::endl;
        std::cout << "5 - допущен или нет ?" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> swap;
            select = stoi(swap);

            if((select > 5) || (select < 0))
                throw std::exception();

        } catch (...){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                list_university[u_index].get_group(g_index).get_student(s_index).list_exam();
                break;
            }
            case 2: {
                list_university[u_index].get_group(g_index).get_student(s_index).list_not_ex();
                break;
            }
            case 3: {
                list_university[u_index].get_group(g_index).get_student(s_index).print_delivered();
                break;
            }
            case 4: {
                list_university[u_index].get_group(g_index).get_student(s_index).print_full_inf();
                break;
            }
            case 5: {
                if(list_university[u_index].get_group(g_index).get_student(s_index).i_allow())
                    std::cout << "Вы допущены" << std::endl;
                else
                    std::cout << "Вы не допущены" << std::endl;
                break;
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}

void System::work_with_groups(int u_index) {
    while(true) {
        int select;
        std::string swap;
        int q = -1;
        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить группу" << std::endl;
        std::cout << "2 - удалить группу" << std::endl;
        std::cout << "3 - список групп в институте" << std::endl;
        std::cout << "4 - работа с группами" << std::endl;
        std::cout << "5 - список допущенных студентов" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> swap;
            select = stoi(swap);

            if((select > 5) || (select < 0))
                throw std::exception();

        } catch (...){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                Group gp;
                list_university[u_index].add_group(gp);
                std::cout << "-- группа успешно добавлена --" << std::endl;
                break;
            }
            case 2: {
                list_university[u_index].delete_group();
                break;
            }
            case 3: {
                list_university[u_index].print_group();
                break;
            }
            case 4: {
                int index;
                list_university[u_index].print_group();
                std::cout << "Выберите группу: ";
                std::cin >> index;
                work_with_students(u_index, index-1);
                q--;
                break;
            }
            case 5: {
                print_all_allow_students();
                break;
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}

void System::work_with_students(int u_index, int g_index) {
    while(true) {
        int select;
        int q = -1;
        std::string swap;

        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить студента" << std::endl;
        std::cout << "2 - удалить студента" << std::endl;
        std::cout << "3 - список студентов в группе" << std::endl;
        std::cout << "4 - работа с планом" << std::endl;
        std::cout << "5 - выдать допуск студенту" << std::endl;
        std::cout << "6 - работа со студентом" << std::endl;
        std::cout << "7 - список допущенных студентов" << std::endl;
        std::cout << "8 - список не допущенных студентов" << std::endl;
        std::cout << "9 - выставить оценку студенту" << std::endl;
        std::cout << "10 - сохранить план" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";
        try {
            std::cin >> swap;
            select = stoi(swap);

            if((select > 10) || (select < 0))
                throw std::exception();

        } catch (...){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                Student gp;
                list_university[u_index].get_group(g_index).add_student(gp);
                std::cout << "-- студент успешно добавлен --" << std::endl;
                break;
            }
            case 2: {
                list_university[u_index].get_group(g_index).delete_student();
                break;
            }
            case 3: {
                list_university[u_index].get_group(g_index).print_group_students();
                break;
            }
            case 4: {
                work_with_plan(u_index, g_index);
                break;
            }
            case 5: {
                list_university[u_index].get_group(g_index).allow_student();
                break;
            }
            case 6: {
                int s_index;
                list_university[u_index].get_group(g_index).print_group_students();
                std::cout << "Выберите студента: ";
                std::cin >> s_index;
                work_with_session(u_index, g_index, s_index - 1);
                break;
            }
            case 7: {
                list_university[u_index].get_group(g_index).print_allow_students();
                break;
            }
            case 8: {
                list_university[u_index].get_group(g_index).print_not_allow_students();
                break;
            }
            case 9: {
                int index;
                list_university[u_index].get_group(g_index).print_group_students();
                std::cout << "Выберите студента: ";
                std::cin >> index;
                list_university[u_index].get_group(g_index).set_mark_student(index - 1);
                break;
            }
            case 10: {
                list_university[u_index].get_group(g_index).save_plan(list_university[u_index].get_group(g_index).get_plan());
                break;
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}

void System::work_with_plan(int u_index, int g_index) {
    while(true) {
        int select;
        int q = -1;
        std::string swap;

        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить предмет в план" << std::endl;
        std::cout << "2 - удалить предмет из плана" << std::endl;
        std::cout << "3 - план группы" << std::endl;
        std::cout << "4 - экзаминацеонные предметы" << std::endl;
        std::cout << "5 - передметы с зачётами" << std::endl;
        std::cout << "6 - работа с передметом" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> swap;
            select = stoi(swap);

            if((select > 6) || (select < 0))
                throw std::exception();

        } catch (...){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                Subject sb;
                list_university[u_index].get_group(g_index).get_plan().add_subject(sb);
                std::cout << "-- передмет успешно добавлен --" << std::endl;
                break;
            }
            case 2: {
                list_university[u_index].get_group(g_index).get_plan().delete_subject_plan();
                break;
            }
            case 3: {
                list_university[u_index].get_group(g_index).get_plan().print_plan();
                break;
            }
            case 4: {
                list_university[u_index].get_group(g_index).get_plan().print_ex_subj();
                break;
            }
            case 5: {
                list_university[u_index].get_group(g_index).get_plan().print_not_ex_subj();
                break;
            }
            case 6: {
                int index;
                list_university[u_index].get_group(g_index).get_plan().print_plan();
                std::cout << "Выберите предмет: ";
                std::cin >> index;
                work_with_task(u_index, g_index, index - 1);
                break;
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}

void System::work_with_task(int u_index, int g_index, int p_index) {
    while(true) {
        int select;
        int q = -1;
        std::string swap;
        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить задание к предмету" << std::endl;
        std::cout << "2 - удалить задание из предмета" << std::endl;
        std::cout << "3 - список заданий предмета" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> swap;
            select = stoi(swap);

            if((select > 3) || (select < 0))
                throw std::exception();

        } catch (...){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                list_university[u_index].get_group(g_index).get_plan().get_subject(p_index).add_task();
                std::cout << "-- задание успешно добавлено --" << std::endl;
                break;
            }
            case 2: {
                list_university[u_index].get_group(g_index).get_plan().get_subject(p_index).delete_task();
                break;
            }
            case 3: {
                list_university[u_index].get_group(g_index).get_plan().get_subject(p_index).print_task_list();
                break;
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}

void System::start() {
    int p_i = 0;
    int select;
    std::string swap;

    while (true) {
        if (p_i != 1) {
            std::cout << std::endl << "_________________________________" << std::endl;
            std::cout << "Учёт успеваемости студентов" << std::endl;
            std::cout << "_________________________________" << std::endl;
            p_i++;
        } else {
            p_i = 0;
        }

        int q = -1;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить ВУЗ" << std::endl;
        std::cout << "2 - удалить ВУЗ" << std::endl;
        std::cout << "3 - список ВУЗов" << std::endl;
        std::cout << "4 - выбрать институт" << std::endl;
        std::cout << "0 - выход" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> swap;
            select = stoi(swap);
            if ((select > 4) || (select < 0))
                throw std::exception();
        } catch (...) {
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (select) {
            case 1: {
                add_university();
                break;
            }
            case 2: {
                delete_university();
                break;
            }
            case 3: {
                print_university();
                break;
            }
            case 4: {
                int index;
                print_university();
                std::cout << "Выберите институт: ";
                std::cin >> index;
                work_with_groups(index - 1);
            }
            case 0: {
                q += 1;
                break;
            }
            default: {
                std::cout << "Данный пункт меню отстутствует" << std::endl;
            }
        }
        if (q == 0)
            break;
    }
}


