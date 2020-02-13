#ifndef UNIVERSITY_MAIN_PLAN_H
#define UNIVERSITY_MAIN_PLAN_H

#include "../subject/Subject.h"
#include <vector>
#include <string>

class Plan {
private:
    std::vector<Subject> list_subject;
    int size = 0;
public:
    void add_subject(std::string, int, bool);
    void delete_subject();
    void print_plan();
};


#endif //UNIVERSITY_MAIN_PLAN_H
