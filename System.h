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
    void work_with_groups(int index = -1);
    void work_with_students(int index = -1, int g_index = -1);
    void work_with_plan(int u_index = -1, int g_index = -1);
    void work_with_task(int u_index = -1, int g_index = -1, int p_index = -1);
};


#endif //UNIVERSITY_MAIN_SYSTEM_H
