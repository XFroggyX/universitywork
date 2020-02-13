#ifndef UNIVERSITY_MAIN_UNIVERSITY_H
#define UNIVERSITY_MAIN_UNIVERSITY_H

#include <vector>
#include <string>
#include "Group.h"

class University {
private:
    std::vector<Group> list_group;
    std::string name_university;
    unsigned size_group = 0;
public:
    void add_group();
    void delete_group();
    void print_group();
};


#endif //UNIVERSITY_MAIN_UNIVERSITY_H
