#ifndef UNIVERSITY_MAIN_SUBJECT_H
#define UNIVERSITY_MAIN_SUBJECT_H

#include "Mark.h"
#include "Tasks_cereator.h"
#include <string>
#include <vector>

class Subject {
private:
    std::vector<Task *> list_tasks;  //список заданий
    std::string name_subject;
    std::string type_subject;
    std::vector<Mark> mark_subj; //оценка за предмет
public:
    Subject();
    ~Subject();

    void change_mark(); //оценка за предмет
    std::string get_name_subject();
    std::string get_type_subject();

    void add_task();
    void delete_task();
    void print_task_list();
    void task_change_mark(bool);
    bool its_ex(); //экзамен ли данный предмет
    std::string get_mark();
    bool subj_delivered(); //сданные ли предмет
    void print_task_delivered();
};


#endif //UNIVERSITY_MAIN_SUBJECT_H
