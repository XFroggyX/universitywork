#ifndef UNIVERSITY_MAIN_SUBJECT_H
#define UNIVERSITY_MAIN_SUBJECT_H

#include "Mark.h"
#include "Tasks_cereator.h"
#include <string>
#include <vector>

class Subject {
private:
    std::vector<Task *> tasks;
    std::string name_subject;
    std::string type_subject;
    unsigned hour_subject = 0;
    Mark *mark;
public:
    Subject();
    Subject(std::string, int);
    Subject(std::string, bool);
    ~Subject();

    void print_name_subject() const;
    void print_subject_mark() const;
    void change_mark(unsigned);
    void change_mark(bool);
    void rename_subj(const std::string& = " ");
    void add_hour(unsigned);
    void print_hour();
    std::string get_name_subject();
    std::string get_type_subject();
    void add_task();
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
