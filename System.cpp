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

void System::print_university() {
    std::cout << "Список ВУЗов: " << std::endl;
    for(int i = 0; i < list_university.size(); i++) {
        std::cout << i + 1  << " " << list_university[i].get_name_university() << std::endl;
    }
}

void System::delete_university() {
    print_university();
    std::cout << "____________________________" << std::endl;
    std::cout << "Введите номер ВУЗа:";
    int index = 0;
    try {
        std::cin >> index;
        int a = index;

        if((index > list_university.size()) || (index < 0))
            throw 1;

    } catch (int a){
        std::cout << "Институт с таким номером отсутствует." << std::endl;
        return;
    }
    list_university.erase(list_university.begin() + index - 1);
    std::cout << "-- ВУЗ успешно удалён --" << std::endl;
}

void System::work_with_groups() {
        int q = 0;
        while(true) {
            std::cout << "____________________________" << std::endl;
            std::cout << "Меню:" << std::endl;
            std::cout << "1 - добавить группу" << std::endl;
            std::cout << "2 - удалить группу" << std::endl;
            std::cout << "3 - список групп в институте" << std::endl;
            std::cout << "0 - назад" << std::endl;
            std::cin >> option;
            switch(option - 1) {
                case 0: {system.addGroup(); break;}
                    // case 1: {system.delGroup(); break;}
                case 3: { q += 1; break;}
            }
            if(q != 0)
                break;
        }
}


