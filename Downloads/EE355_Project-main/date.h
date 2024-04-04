#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;


class Date {
private:
	string day;
    string month;
    string year;

public:
    Date(string datestr);
	void print_date(string format);
    string get_date(string format);
    bool operator==(const Date& rhs);
  bool operator!=(const Date& rhs);
};


#endif