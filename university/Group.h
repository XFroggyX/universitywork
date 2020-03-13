#ifndef UNIVERSITY_MAIN_GROUP_H
#define UNIVERSITY_MAIN_GROUP_H

#include <vector>
#include "../objectives of the group/Student.h"
#include "../objectives of the group/Plan.h"
#include <string>

class Group {
private:
    Plan group_plan;
    std::vector<Student> list_students;
    std::string group_name;
    unsigned size_group = 0;
    int allow_students = 0;
public:
    Group();
    explicit Group(std::string);
    void add_student(const Student&);
    Student& get_student(int);
    Plan& get_plan();
    void print_allow_students();
    void print_not_allow_students();
    std::string get_name_group() const;
    void delete_student(int i = -1);
    void print_group_students();
    void allow_student();
    void set_mark_student(int);
    void save_plan(const Plan&);
};


#endif //UNIVERSITY_MAIN_GROUP_H
