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
    std::string get_name_student() const;
    void delStudent(int);
    void print_subject_session();
    void print_session();
    void allow(Plan);
    bool itsallow();
    Session &get_session();
    unsigned average_score();
    unsigned items_session();
};


#endif //UNIVERSITY_MAIN_STUDENT_H
