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
    std::cout << "Введите номер студента:";
    int student_index = 0;
    try {
        std::cin >> student_index;

        if((student_index > list_students.size()) || (student_index < 0))
            throw 1;

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


