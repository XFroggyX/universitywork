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
    void delete_task();
    void print_task_list();
    bool its_subj();
    std::string get_name_subject();
    std::string get_type_subject();
    void add_task();
    void task_change_mark();
    bool subj_delivered();
    void print_task_delivered();
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
