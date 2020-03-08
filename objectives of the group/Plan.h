#ifndef UNIVERSITY_MAIN_PLAN_H
#define UNIVERSITY_MAIN_PLAN_H

#include "../subject/Subject.h"
#include <vector>
#include <string>

class Plan {
private:
    std::vector<Subject> list_subjects;
    unsigned items_plan = 0;
public:
    void add_subject(Subject);
    Subject& get_subject(int i);
    void delete_subject_plan();
    void print_plan();
    void print_ex_subj();
    void print_notex_subj();
};


#endif //UNIVERSITY_MAIN_PLAN_H
