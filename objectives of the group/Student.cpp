#include "Student.h"

#include <utility>

std::string studstr(std::string input_string) {
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

Student::Student() {
    std::cout << "Введите ФИО студента:";
    std::string new_name_student;
    getline(std::cin, new_name_student);
    new_name_student = studstr(new_name_student);
    name_student = new_name_student;
}

Student::Student(std::string new_name_student) : name_student(std::move(new_name_student)) {
}

std::string Student::get_name_student() const {
    return name_student;
}

