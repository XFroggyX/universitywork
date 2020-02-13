#ifndef UNIVERSITY_MAIN_SUBJECT_H
#define UNIVERSITY_MAIN_SUBJECT_H

#include "Mark.h"
#include <string>

class Subject {
private:
    static std::string name_subject;
    std::string type_subject = "NULL";
public:
    Subject(std::string); //попробывать заполнить type_subject
    ~Subject();
    void set_type(std::string); //попробывать изменить тип переменной
    void set_mark(int);
    void set_mark(bool);
    void print_mark();
private:
    int *mark<name_subject>;
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
