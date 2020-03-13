#include "Mark.h"

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

Mark::Mark() {
    std::string str_mark;
    std::cout << "Выберите тип оценки: " << std::endl;
    std::cout << "1. Зачёт" << std::endl;
    std::cout << "2. Диф. зачёт" << std::endl;
    std::cout << "Ввод: ";

    try{
        std::cin >> str_mark;
        str_mark = rtrim(ltrim(str_mark));

        if ((str_mark != "1") && (str_mark != "2"))
            throw std::exception();
    } catch (...) {
        std::cout << "Данный пункт меню отстутствует оценка задана автоматически." << std::endl;
        mark = "1";
        type = "Диф. зачёт";
    }

    if(str_mark == "1") {
        mark = "No";
        type = "Зачёт";
    } else if(str_mark == "2") {
        mark = "1";
        type = "Диф. зачёт";
    } else {
        mark = "1";
        type = "Диф. зачёт";
        std::cout <<"Ошибка ввода. Значения были заданы автоматически." << std::endl;
    }
}

Mark::Mark(int) {
    mark = "1";
    type = "Диф. зачёт";
}

Mark::Mark(bool) {
    mark = "Не зачёт";
    type = "Зачёт";
}

Mark::~Mark() = default;

void Mark::change_mark() {
    if(type == "Зачёт") {
        std::string _new_mark = "No";

        if (mark == "No") {
            std::cout << "Желаете поставтить зачёт?" << std::endl;
            std::cout << "Ввод (Yes/No): ";
            std::cin >> _new_mark;
            _new_mark = ltrim(rtrim(_new_mark));
        }

        if (_new_mark == "No") {
            mark = "No";
        } else if (_new_mark == "Yes") {
            mark = "Yes";
        } else {
            std::cout << "Ошибка ввода оценки." << "Оценка неизменна" << std::endl;
            return;
        }

    } else if(type == "Диф. зачёт") {
        std::string str_mark;
        std::cout << "Введите новую оценку: ";
        std::cin >> str_mark;
        int new_mark = 0;
        str_mark = ltrim(rtrim(str_mark));

        try {
            new_mark = stoi(str_mark);
        } catch (...) {
            std::cout << "Изменение неудалось. Вы ввели не число." << "Оценка неизменна." <<  std::endl;
            return;
        }

        try {
            if ((new_mark < 1) || (new_mark > 5))
                throw std::exception();
            else
                mark = std::to_string(new_mark);
        } catch (...) {
            std::cout << "Вы вышли за пределы допустмых значений. Значение оценки было не изменено." << std::endl;
            return;
        }
    }
}

int Mark::return_mark() {
    if(type == "Зачёт"){
        if(mark == "Yes") {
            return 1;
        } else {
            return 0;
        }
    } else {
        int a = stoi(mark);
        return a;
    }
}

std::string Mark::return_type() {
    return type;
}

void Mark::change_type_int() {
    mark = "1";
    type = "Диф. зачёт";
}

void Mark::set_mark(int new_mark) {
    mark = std::to_string(new_mark);
}

