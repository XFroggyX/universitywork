#include "Group.h"

#include <utility>

std::string groupstr(std::string input_string) {
    std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    input_string.erase(
            input_string.begin(),
            find_if(input_string.begin(), input_string.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return input_string;
}


Group::Group() {
    std::string new_group_name;
    std::cout << "Введите название группы: ";
    std::cin >> new_group_name;
    new_group_name = groupstr(new_group_name);
    group_name = new_group_name;
    size_group++;
}

Group::Group(std::string new_group_name) : group_name(std::move(new_group_name)) {
    size_group++;
}

void Group::add_student(const Student& new_student) {
    list_students.push_back(new_student);
}

Student &Group::get_student(int i) {
    return list_students[i];
}

Plan &Group::get_plan() {
    return group_plan;
}

std::string Group::get_name_group() const {
    return group_name;
}

void Group::delete_student(int i) {
    print_group_students();
    std::cout << std::endl << "____________________________" << std::endl;
    std::cout << "Введите номер студента: ";
    int student_index = 0;
    try {
        std::cin >> student_index;

        if((student_index > list_students.size()) || (student_index < 0))
            throw std::exception();

    } catch (int a){
        std::cout << "Студент с таким номером отсутствует." << std::endl;
        return;
    }
    list_students.erase(list_students.begin() + i);
    std::cout << "-- студент успешно удалён --" << std::endl;
}

void Group::print_group_students() {
    std::cout << "Список студентов: " << std::endl;
    for (int i = 0; i < list_students.size(); i++) {
        std::cout << i + 1 << ". " << list_students[i].get_name_student() << std::endl;
    }
}

void Group::allow_student() {
    print_group_students();
    std::cout << "Кого вы хотите допустить к экзамену ?" << std::endl;
    int index;
    std::cout << "Ввод: ";
    std::cin >> index;
    list_students[index - 1].allow();
    allow_students++;
}

void Group::print_allow_students() {
    std::cout << "Список студентов(допущены): " << std::endl;
    for (int i = 0; i < list_students.size(); i++) {
        if(list_students[i].i_allow())
            std::cout << i + 1 << ". " << list_students[i].get_name_student() << std::endl;
    }
}

void Group::print_not_allow_students() {
    std::cout << "Список студентов(не допущены): " << std::endl;
    for (int i = 0; i < list_students.size(); i++) {
        if(!list_students[i].i_allow())
            std::cout << i + 1 << ". " << list_students[i].get_name_student() << std::endl;
    }
}

void Group::set_mark_student(int s_index) {
    std::cout << "Вы желаете выставить оценку за передмет или за задание ?" << std::endl;
    std::cout << "1. Оценка за предмет" << std::endl << "2. Оценка за задание" << std::endl;
    int select;
    std::cout << "Ввод: ";
    std::cin >> select;
    if(select == 1) {
        list_students[s_index].get_session().get_plan_session().print_plan();
        int p_index;
        std::cout << "Выберите предмет: ";
        std::cin >> p_index;
        list_students[s_index].get_session().get_plan_session().get_subject(p_index - 1).change_mark();
    }else if(select == 2) {
        list_students[s_index].get_session().get_plan_session().print_plan();
        int p_index;
        std::cout << "Выберите предмет: ";
        std::cin >> p_index;
        bool student_allow = list_students[s_index].i_allow();
        list_students[s_index].get_session().get_plan_session().get_subject(p_index - 1).task_change_mark(student_allow);
    } else {
        std::cout << "Выбран не верный тип" << std::endl;
    }
}

void Group::save_plan(const Plan& pl) {
    for(auto & list_student : list_students) {
        list_student.save_plan(pl);
    }
}


