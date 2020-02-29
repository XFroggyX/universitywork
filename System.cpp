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
    std::cout << std::endl << "____________________________" << std::endl;
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

void System::work_with_groups(int u_index) {
    while(true) {
        int select;
        int q = 0;
        int option = 0;
        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить группу" << std::endl;
        std::cout << "2 - удалить группу" << std::endl;
        std::cout << "3 - список групп в институте" << std::endl;
        std::cout << "4 - работа с группами" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";
        try {
            std::cin >> select;

            if((select > 3) || (select < 0))
                throw 1;

        } catch (int a){
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            return;
        }

        switch (select) {
            case 1: {
                Group gp;
                list_university[u_index].add_group(gp);
                std::cout << "-- группа успешно добавлена --" << std::endl;
                break;
            }
            case 2: {
                list_university[u_index].delete_group();
                break;
            }
            case 3: {
                list_university[u_index].print_group();
                break;
            }
            case 0: {
                q += 1;
                break;
            }
        }
        if (q != 0)
            break;
    }
}


