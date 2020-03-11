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
    void add_subject(const Subject&);
    void delete_subject_plan();

    void print_plan();
    void print_ex_subj();
    void print_not_ex_subj();

    Subject& get_subject(int i);
    int get_size_plan();
};


#endif //UNIVERSITY_MAIN_PLAN_H
