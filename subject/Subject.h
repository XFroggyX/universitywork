#ifndef UNIVERSITY_MAIN_SUBJECT_H
#define UNIVERSITY_MAIN_SUBJECT_H

#include "Mark.h"
#include <string>

class Subject {
private:
    std::string name_subject;
    std::string type_subject;
    unsigned hour_subject = 0;
    Mark<int> int_mark;
    Mark<bool> bool_mark;
    int *mark;
public:
    Subject(std::string, int);
    Subject(std::string, bool);
    Subject(std::string, std::string);
    ~Subject();

    void set_mark(unsigned);
    void set_mark(bool);
    void change_mark(unsigned);
    void change_mark(bool);
    void rename_subj(std::string);
    void add_hour(unsigned);
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
