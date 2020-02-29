#include "University.h"

#include <utility>

std::string unistr(std::string input_string) {
    std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    input_string.erase(
            input_string.begin(),
            find_if(input_string.begin(), input_string.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return input_string;
}

University::University() {
    std::string new_name_university_;
    std::cout << "Введите название университета: " << std::endl;
    std::cin >> new_name_university_;
    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    new_name_university_ = unistr(new_name_university_);
    name_university = new_name_university_;
}

University::University(std::string name_university_) : name_university(std::move(name_university_)) {
}

void University::add_group(const Group& new_group) {
    list_groups.push_back(new_group);
    size_group++;
}

std::string University::get_name_university() const {
    return name_university;
}

std::vector<Group> University::get_group() const {
    return list_groups;
}

Group &University::get_group(int i)  {
    return list_groups[i];
}

void University::delete_group(int i) {
    list_groups.erase(list_groups.begin() + i);
}

void University::print_name_university() {
    std::cout << "Назавание институту: " << name_university << std::endl;
}
/*
void University::print_group() const {
    std::cout << "Список групп: " << std::endl;
    for(int i = 0; i < list_groups.size(); i++) {
        std::cout << i + 1 << ". " << list_groups.print_group() << std::endl;
    }
}
*/