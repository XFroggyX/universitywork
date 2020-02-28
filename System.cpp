#include "System.h"

std::string sysstr(std::string input_string) {
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

void System::add_university() {
    University un;
    list_university.push_back(un);
    std::cout << "-- ВУЗ успешно добавлен --" << std::endl;
}
