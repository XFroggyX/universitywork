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

void Plan::add_subject(Subject subject) {
    list_subject.push_back(subject);
}

/*
void Plan::print_plan() {
    std::cout << "Предметы в плане:" << std::endl;
    for(int i = 0; i < plan_sub.size(); i++) {
        std::cout << "#" << i << plan_sub[i] << std::endl;
    }
}

void Plan::delete_subject() {
    print_paln();
    std::cout << "Какой предмет желаете удалить из плана. ";
    std::cout << "Введите индекс элемента: " << std::endl;
    int index;
    std::cin >> index;
    plan_sub.erase(plan_sub.begin() + index);
}
*/