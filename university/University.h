#ifndef UNIVERSITY_MAIN_UNIVERSITY_H
#define UNIVERSITY_MAIN_UNIVERSITY_H

#include <vector>
#include <string>
#include "Group.h"

class University {
private:
    std::vector<Group> list_groups;
    std::string name_university;
public:
    University();
    explicit University(std::string);
    std::string get_name_university() const;
    void add_group(const Group&);
    Group& get_group(int);
    void delete_group();
    void print_group() const;
};


#endif //UNIVERSITY_MAIN_UNIVERSITY_H
