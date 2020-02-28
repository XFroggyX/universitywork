#ifndef UNIVERSITY_MAIN_STUDENT_H
#define UNIVERSITY_MAIN_STUDENT_H

#include <string>
#include "Session.h"
#include <vector>

class Student {
private:
    std::string name_student;
    //Session student_session;
    bool allows = false;
public:
    Student();
    Student(std::string);


    //void addExam(Exam);
    //Exam& getExam(int);
    // vector<Exam> getExams() const;

    std::string get_name_student() const;


    void delStudent(int);
    void print_session();
    bool allow();
    unsigned average_score();
    unsigned items_session();
};


#endif //UNIVERSITY_MAIN_STUDENT_H
