#include <iostream>
#include "System.h"

int main() {
    setlocale(LC_ALL, "Russian");

    System system;
    int p_i = 1;
    int option = 0;

    while(true){
        while (true) {
            if (p_i != 1) {
                std::cout << std::endl << "_________________________________" << std::endl;
                std::cout << "Учёт успеваемости студентов" << std::endl;
                std::cout << "_________________________________" << std::endl;
            } else {
                p_i = 0;
            }

            std::cout << "Меню:" << std::endl;
            std::cout << "1 - институт" << std::endl;
            std::cout << "2 - группа" << std::endl;
            std::cout << "3 - студенты" << std::endl;
            std::cout << "4 - план" << std::endl;
            std::cout << "5 - оценка" << std::endl;
            std::cout << "6 - вывести отчет" << std::endl;
            std::cout << "0 - завершить работу программы" << std::endl;
            std::cout << "Ввод: ";
            try {
                std::cin >> option; // Запрашиваем у пользователя пункт меню
                int a = option;
                if((option > 6) || (option < 0))
                    throw ;
            }catch (int a) {
                std::cout << "Данный пункт меню отсутствует" << std::endl;
                continue;
            }

// Используем оператор switch для обработки выбранного пункта меню
            switch (option) {
                case 1: {
                    int q = 0;
                    while(true) {
                        std::cout << "____________________________" << std::endl;
                        std::cout << "Меню:" << std::endl;
                        std::cout << "1 - добавить ВУЗ" << std::endl;
                        std::cout << "2 - удалить ВУЗ" << std::endl;
                        std::cout << "0 - назад" << std::endl;
                        std::cout << "Ввод: ";
                        std::cin >> option;
                        switch(option) {
                            case 1: {system.add_university(); break;}
                            //case 2: {system.delUniversity(); break;}
                            case 0: { q += 1; break;}
                        }
                        if(q != 0)
                            break;
                        //system.printReport();
                    }

                    break;
                }
                case 2: {
                    int q = 0;
                    while(true) {
                        std::cout << "____________________________" << std::endl;
                        std::cout << "Меню:" << std::endl;
                        std::cout << "0 - добавить группу" << std::endl;
                        std::cout << "1 - удалить группу" << std::endl;
                        std::cout << "3 - назад" << std::endl;
                        std::cin >> option;
                        switch(option) {
                            //case 0: {system.addGroup(); break;}
                           // case 1: {system.delGroup(); break;}
                            case 3: { q += 1; break;}
                        }
                        if(q != 0)
                            break;
                       // system.printReport();
                    }
                    break;
                }
                case 3: {
                    int q = 0;
                    while(true) {
                        std::cout << "____________________________" << std::endl;
                        std::cout << "Меню:" << std::endl;
                        std::cout << "0 - добавить студента" << std::endl;
                        std::cout << "1 - удалить студента" << std::endl;
                        std::cout << "3 - назад" << std::endl;
                        std::cin >> option;
                        switch(option) {
                          //  case 0: {system.addStudent(); break;}
                           // case 1: {system.delStudent(); break;}
                            case 3: { q += 1; break;}
                        }
                        if(q != 0)
                            break;
                        //system.printReport();
                    }
                    break;
                }
                case 4: {
                    int q = 0;
                    while(true) {
                        std::cout << "____________________________" << std::endl;
                        std::cout << "Меню:" << std::endl;
                        std::cout << "0 - добавить экзамен" << std::endl;
                        std::cout << "0 - добавить экзамен" << std::endl;
                        std::cout << "1 - удалить экзамен" << std::endl;
                        std::cout << "3 - назад" << std::endl;
                        std::cin >> option;
                        switch(option) {
                           // case 0: {system.addExam(); break;}
                          //  case 1: {system.delExam(); break;}
                            case 3: { q += 1; break;}
                        }
                        if(q != 0)
                            break;
                       // system.printReport();
                    }
                    break;
                }
                case 5: {
                    //system.setMark();
                    break;
                }
                case 6: {
                  //  system.printReport();
                    break;
                }
                case 0: {
                    /*сохраняем данные*/
                    // system.saveReport();
                    return 0;
                }
                default:
                    break;
            }
        }
        return 0;
    }
}