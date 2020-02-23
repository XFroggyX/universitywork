#ifndef UNIVERSITY_MAIN_GROUP_H
#define UNIVERSITY_MAIN_GROUP_H

#include <vector>
#include "../objectives of the group/Student.h"
#include "../objectives of the group/Plan.h"
#include <string>

class Group {
private:
    std::vector<Student> list_students;
    std::vector<Student> list_allows_students;
    std::string group_name;
    unsigned size_group{};
public:
    Group();
    Group(std::string);
    void add_student(const Student&);
    Student& get_student(int);
    std::string get_id() const;
    std::vector<Student> get_students() const;
    void delete_student(int);
    void print_group();
    void allow_student();
};


#endif //UNIVERSITY_MAIN_GROUP_H
