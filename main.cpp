#include <iostream>
#include "System.h"

int main() {
    setlocale(LC_ALL, "Russian");

    System system;
    int p_i = 1;
    int option = 0;

    while (true) {
        if (p_i != 1) {
            std::cout << std::endl << "_________________________________" << std::endl;
            std::cout << "Учёт успеваемости студентов" << std::endl;
            std::cout << "_________________________________" << std::endl;
        } else {
            p_i = 0;
        }

        int q = 0;
        std::cout << "____________________________" << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1 - добавить ВУЗ" << std::endl;
        std::cout << "2 - удалить ВУЗ" << std::endl;
        std::cout << "3 - список ВУЗов" << std::endl;
        std::cout << "4 - выбрать институт" << std::endl;
        std::cout << "0 - назад" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> option;

        try {
            std::cin >> option;
            int a = option;
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
                system.work_with_groups();
            }
            case 0: {
                q += 1;
                break;
            }
        }
        if (q != 0)
            break;
    }
    return 0;
}
            /*
                }
                case 2: {
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

                    // system.saveReport();
                    return 0;
                }
                default:
                    break;
            }
        }*/

