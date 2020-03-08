#include <iostream>
#include "System.h"

#include "subject/Subject.h"
int main() {
    setlocale(LC_ALL, "Russian");

    System system;
    int p_i = 0;
    int option = 0;

    while (true) {
        if (p_i != 1) {
            std::cout << std::endl << "_________________________________" << std::endl;
            std::cout << "Учёт успеваемости студентов" << std::endl;
            std::cout << "_________________________________" << std::endl;
            p_i++;
        } else {
            p_i = 0;
        }

        int q = -1;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить ВУЗ" << std::endl;
        std::cout << "2 - удалить ВУЗ" << std::endl;
        std::cout << "3 - список ВУЗов" << std::endl;
        std::cout << "4 - выбрать институт" << std::endl;
        std::cout << "0 - выход" << std::endl;
        std::cout << "Ввод: ";

        try {
            std::cin >> option;
            if ((option > 4) || (option < 0))
                throw;
        } catch (int a) {
            std::cout << "Данный пункт меню отсутствует" << std::endl;
            continue;
        }

        switch (option) {
            case 1: {
                system.add_university();
                break;
            }
            case 2: {
                system.delete_university();
                break;
            }
            case 3: {
                system.print_university();
                break;
            }
            case 4: {
                int index;
                system.print_university();
                std::cout << "Выберите институт: ";
                std::cin >> index;
                system.work_with_groups(index - 1);
            }
            case 0: {
                q += 1;
                break;
            }
        }
        if (q == 0)
            break;
    }
    return 0;
}


