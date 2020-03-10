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
    std::cin >> new_name_student;
    new_name_student = studstr(new_name_student);
    name_student = new_name_student;
}

std::string Student::get_name_student() const {
    return name_student;
}

void Student::allow(Plan pl) {
    Session ss(std::move(pl));
    student_session.push_back(ss);
    allows = true;
}

bool Student::itsallow() {
    return allows;
}

void Student::print_subject_session() {
    student_session[0].get_session().print_plan();
}

Session &Student::get_session() {
    return student_session[0];
}

void Student::list_exam() {
    student_session[0].get_session().print_ex_subj();
}

void Student::list_not_ex() {
    student_session[0].get_session().print_notex_subj();
}

void Student::print_delivered() {
    student_session[0].print_arrears();
}

void Student::print_full_inf() {
    student_session[0].print_inf();
}

bool Student::i_allow() {
    return allows;
}


