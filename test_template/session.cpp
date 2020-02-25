#include "session.h"

void Session::set_date_start(int day, int month, int year) {
    string date;
    if(month < 9)
        date += "0";
    ostringstream sr;
    sr << day << '.' << date << month << '.' << year;
    date_start = sr.str();
}

void Session::set_date_end(int day, int month, int year) {
    string date;
    if(month < 9)
        date += "0";
    ostringstream sr;
    sr << day << '.' << date << month << '.' << year;
    date_end = sr.str();
}

void Session::set_mark() {
    cout << "Введите id экзамена, по какому нужно поставить оценку :";
}


