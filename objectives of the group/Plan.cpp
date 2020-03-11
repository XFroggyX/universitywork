#include "Plan.h"

std::string planstr(std::string input_string) {
    std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    input_string.erase(
            input_string.begin(),
            find_if(input_string.begin(), input_string.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return input_string;
}

void Plan::add_subject(const Subject& subject) {
    list_subjects.push_back(subject);
    items_plan++;
}

Subject &Plan::get_subject(int i) {
    return list_subjects[i];
}

void Plan::print_plan() {
    std::cout << "Список работ:" << std::endl;
    for(int i = 0; i < list_subjects.size(); i++) {
        std::cout << i + 1  << ". " << list_subjects[i].get_name_subject()  << " "
            << list_subjects[i].get_type_subject() << std::endl;
    }
}

void Plan::print_ex_subj() {
    std::cout << "План работ(экзамены):" << std::endl;
    for(int i = 0; i < list_subjects.size(); i++) {
        if(list_subjects[i].its_ex())
            std::cout << i + 1  << ". " << list_subjects[i].get_name_subject()
                << " " << list_subjects[i].get_type_subject() << std::endl;
    }
}

void Plan::print_not_ex_subj() {
    std::cout << "План работ(зачёты):" << std::endl;
    for(int i = 0; i < list_subjects.size(); i++) {
        if(!list_subjects[i].its_ex())
            std::cout << i + 1  << ". " << list_subjects[i].get_name_subject()  << " "
                << list_subjects[i].get_type_subject() << std::endl;
    }
}

void Plan::delete_subject_plan() {
    print_plan();
    std::cout << "Какой предмет желаете удалить из плана? ";
    std::cout << "Введите индекс предмет: " << std::endl;
    int index;
    try {
        std::cin >> index;
        if((index > items_plan) || (items_plan < 0)){
            throw 1;
        }

    } catch(...) {
        std::cout << "Данный предмет отсутствует. Предмет неудалён." << std::endl;
        return;
    }
    list_subjects.erase(list_subjects.begin() + index - 1);
    items_plan--;
}

int Plan::get_size_plan() {
    return (int)items_plan;
}

