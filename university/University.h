#ifndef UNIVERSITY_MAIN_UNIVERSITY_H
#define UNIVERSITY_MAIN_UNIVERSITY_H

#include <vector>
#include <string>
#include "Group.h"

class University {
private:
    std::vector<Group> list_groups;
    std::string name_university;
    unsigned size_group = 0;
public:
    University();
    University(std::string);
    std::string get_name_university() const;
    void add_group(const Group&);
    Group& get_group(int);
    std::vector<Group> get_group() const;
    void delete_group(int);
    void print_group() const;
};


#endif //UNIVERSITY_MAIN_UNIVERSITY_H
