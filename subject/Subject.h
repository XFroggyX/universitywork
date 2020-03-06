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
    std::vector<Mark> mark_subj;
public:
    Subject();
    ~Subject();

    void print_name_subject() const;
    void print_subject_mark();
    void change_mark();
    void rename_subj(const std::string& = " ");
    void add_hour(unsigned);
    void print_hour();
    void print_task_name();
    std::string get_name_subject();
    std::string get_type_subject();
    void add_task();
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
