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
    //void delete_subject_plan();
    void print_plan();
   // unsigned size_plan();
};


#endif //UNIVERSITY_MAIN_PLAN_H
