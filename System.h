#ifndef UNIVERSITY_MAIN_SYSTEM_H
#define UNIVERSITY_MAIN_SYSTEM_H

#include <vector>
#include "university/University.h"

class System {
private:
    unsigned size_university;
    std::vector<University> list_university;
public:
    void add_university();
    void delete_university();
    void print_university();
    void work_with_groups();
    void print_full_information_university();
    void work_with_students();
    void work_with_subjects();
};


#endif //UNIVERSITY_MAIN_SYSTEM_H
