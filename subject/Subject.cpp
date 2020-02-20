#include "Subject.h"

std::string split_string(std::string input_string) {
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

Subject::Subject() {
    std::string name_sub;
    std::cout << "Введите название предмета: ";
    getline(std::cin, name_sub);
    name_sub = split_string(name_sub);
    name_subject = name_sub;

    std::cout << "Выберите тип оценки: " << std::endl;
    std::cout << "1. Зачёт" << std::endl;
    std::cout << "2. Дифференцированный зачёт/Экзамен" << std::endl;
    std::cout << "Ввод: ";
    int select = 0;
    try {
        std::cin >> select;
        if((select != 1) && (select != 2))
            throw;
    } catch(int a) {
        std::cout << "Выбрано значение в не диапазона. Предмет небыл добавлен." << std::endl;
        return ;
    }

    if(select == 1) {
        type_subject = "Bool";
        //mark = new Bool_mark();
    } else {
        type_subject = "Int";
        mark = Int_mark();
}
}

Subject::Subject(std::string name_sub, int i_new_mark) {
    name_sub = split_string(name_sub);
    name_subject = name_sub;
    try {
        if((i_new_mark < 1) || (i_new_mark > 5))
            throw;
        else {
            type_subject = "Int";
            Int_mark new_mark(i_new_mark);
            //mark = &new_mark;
        }
    } catch (int a) {
        std::cout << "Выход из диапазона возможных оценок. Значение было задано по умолчанию." << std::endl;
        type_subject = "Int";
        Int_mark new_mark(1);
       // mark = &new_mark;
    }
}

Subject::Subject(std::string name_sub, bool bmark) {
    name_sub = split_string(name_sub);
    name_subject = name_sub;
    type_subject = "Bool";
    Bool_mark new_markq(bmark);
   // mark = &new_markq;
}

void Subject::add_hour(unsigned) {
        std:: cout << mark.return_mark();
}

Subject::~Subject() = default;
