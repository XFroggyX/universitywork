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

void Mark::change_mark(int new_mark) {
    mark = new_mark;
}

void Mark::print_mark() {
    std::cout << mark;
}

int Mark::return_mark() {
    return mark;
}

Int_mark::Int_mark() {
    std::string str_mark;
    std::cout << "Введите новую оценку: ";
    std::cin.ignore();
    std::getline(std::cin, str_mark);

    str_mark = ltrim(rtrim(str_mark));
    int new_mark;
    try {
        new_mark = stoi(str_mark);
    } catch(...) {
        std::cout <<"Изменение неудалось. Вы ввели не число. Установлено значение по умолчанию.";
        mark = 1;
        return ;
    }

    try {
        if((new_mark < 1) || (new_mark > 5))
            throw 1;
        else
            mark = new_mark;
    } catch(int a) {
        std::cout << "Вы вышли за пределы допустмых значений. Значение оценки было установлино по умолчанию." << std::endl;
        mark = 1;
    }
}

Int_mark::Int_mark(int new_mark) {
    try {
        if((new_mark < 1) || (new_mark > 5))
            throw 1;
        else
            mark = new_mark;
    } catch(int a) {
            std::cout << "Вы вышли за пределы допустмых значений. Значение оценки было задано, как 1." << std::endl;
            mark = 1;
    }
}

void Int_mark::change_mark(int new_mark = 0) {
    if(new_mark == 0 ) {
        std::string str_mark;
        std::cout << "Введите новую оценку: ";
        std::cin >> str_mark;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        str_mark = ltrim(rtrim(str_mark));
        try {
            new_mark = stoi(str_mark);
        } catch(...) {
            std::cout <<"Изменение неудалось. Вы ввели не число";
        }
    }

    try {
        if((new_mark < 1) || (new_mark > 5))
            throw 1;
        else
            mark = new_mark;
    } catch(int a) {
        std::cout << "Вы вышли за пределы допустмых значений. Значение оценки было не изменено." << std::endl;
    }
}

void Int_mark::print_mark() const {
    std::cout << "Ваша оценка: " << mark << std::endl;
}

int Int_mark::return_mark() const {
    return mark;
}

Int_mark::~Int_mark() = default;

Bool_mark::Bool_mark() {
    std::string str_mark;
    std::cout << "Выберите оценку: " << std::endl << "1. Зачёт" << std::endl;
    std::cout << "2. Не зачёт" << std::endl << "Ввод: ";
    std::cin >> str_mark;

    str_mark = ltrim(rtrim(str_mark));
    int int_mark = stoi(str_mark);

    if(int_mark == 1) {
        mark = 1;
    } else if(int_mark == 2) {
        mark = 0;
    } else {
        std::cout << "Вы выбрали неверное значение." << std::endl;
        return ;
    }
}

Bool_mark::Bool_mark(bool new_mark) {
        mark = new_mark;
}

void Bool_mark::change_mark(bool new_mark) {
    if(!new_mark) {
        std::string str_mark;
        std::cout << "Выберите оценку: " << std::endl << "1. Зачёт" << std::endl;
        std::cout << "2. Не зачёт" << std::endl << "Ввод: ";
        std::cin >> str_mark;

        str_mark = ltrim(rtrim(str_mark));
        int int_mark = stoi(str_mark);

        if(int_mark == 1) {
            mark = 1;
        } else if(int_mark == 2) {
            mark = 0;
        } else {
            std::cout << "Вы выбрали неверное значение. Оценка не была изменена" << std::endl;
            return ;
        }
    } else {
        mark = new_mark;
    }
}

void Bool_mark::print_mark() const {
    if(mark == 0) {
        std::cout << "Ваша оценка: " << "Незачёт" << std::endl;
    } else {
        std::cout << "Ваша оценка: " << "Зачёт" << std::endl;
    }
}

int Bool_mark::return_mark() const {
    return mark;
}

Bool_mark::~Bool_mark() = default;


