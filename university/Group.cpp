#include "Group.h"

#include <utility>

std::string split_string(std::string input_string) {
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
    new_group_name = split_string(new_group_name);
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

std::string Group::get_id() const {
    return group_name;
}

std::vector<Student> Group::get_students() const {
    return list_students;
}

void Group::delete_student(int i) {
    list_students.erase(list_students.begin() + i);
}


