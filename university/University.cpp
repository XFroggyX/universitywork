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
    size_university++;
}

std::string University::get_name_university() const {
    return name_university;
}

Group &University::get_group(int i)  {
    return list_groups[i];
}

void University::delete_group() {
    print_group();
    std::cout << std::endl << "____________________________" << std::endl;
    std::cout << "Введите номер ВУЗа:";
    int group_index = 0;
    try {
        std::cin >> group_index;

        if((group_index > list_groups.size()) || (group_index < 0))
            throw std::exception();

    } catch (...){
        std::cout << "Группа с таким номером отсутствует." << std::endl;
        return;
    }
    list_groups.erase(list_groups.begin() + group_index - 1);
    size_university--;
    std::cout << "-- группа успешно удалён --" << std::endl;
}


void University::print_group() const {
    std::cout << "Список групп: " << std::endl;
    for(int i = 0; i < list_groups.size(); i++) {
        std::cout << i + 1 << ". " << list_groups[i].get_name_group() << std::endl;
    }
}

void University::print_all_allow_students() {
    for(int i = 0; i < size_university; i++) {
        std::cout << "В группе " << list_groups[i].get_name_group() << " допущенны следующие студенты: "  << std::endl;
        list_groups[i].print_allow_students();
    }
}
