#ifndef UNIVERSITY_MAIN_GROUP_H
#define UNIVERSITY_MAIN_GROUP_H

#include <vector>
#include "../objectives of the group/Student.h"
#include "../objectives of the group/Plan.h"
#include <string>

class Group {
private:
    std::vector<Student> list_students;
    Plan *plan;
    std::string group_name;
    unsigned size_group;
    std::vector<Student> list_allows_students;
public:
    void add_student();
    void delete_student();
    void print_group();
    void allow_student();
};


#endif //UNIVERSITY_MAIN_GROUP_H
