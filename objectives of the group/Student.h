#ifndef UNIVERSITY_MAIN_STUDENT_H
#define UNIVERSITY_MAIN_STUDENT_H

#include <string>
#include "Session.h"
#include <vector>

class Student {
private:
    std::string name_student;
    std::vector<Session> student_session;
    bool allows = false;
public:
    Student();
    bool i_allow();
    void allow();
    std::string get_name_student() const;
    void print_subject_session();
    void list_exam();
    void list_not_ex();
    Session &get_session();
    void print_delivered();
    void print_full_inf();
    void save_plan(Plan);
};


#endif //UNIVERSITY_MAIN_STUDENT_H
