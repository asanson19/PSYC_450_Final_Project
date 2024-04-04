
#include "date.h"
#include <stdlib.h>     

string convertMonthInToString(int num){
    const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if(num > 0 && num < 13){
        return months[num -1];
    }
    else{
        return "";
    }
}

int convertMonthStringToInt(string month){
    const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i < 12;i ++){
        if(months[i] == month) return i + 1;
    }
    return -1;
}

//want to make all elements strings so we can parse and isolate them
Date::Date(string datestr){
    // TODO: Complete me! (done)
    bool monthDone = false;
    int monthEndId = 0;
    int dateEndId = 0;
    for(int i = 0; i<datestr.size(); i++){
        if(datestr[i] == '/'){
            if(!monthDone){
                //setting foundmonth flag to true
                monthDone = true;
                // int monthNum = stoi(datestr.substr(0,i));
                // month = convertMonthInToString(monthNum);

                monthEndId = i;
                month=datestr.substr(0,monthEndId);
                month=convertMonthInToString(stoi(month));
                
            }else{
                //monthdone flag already set to true
                // day = stoi(datestr.substr(monthEndId+1,i-monthEndId-1));
                dateEndId = i;
                //difference between dayid and monthid gives us num of digits
                //representing day
                int days=dateEndId-monthEndId -1;
                day=datestr.substr(monthEndId+1,days);
            }
        }
    }

    year=datestr.substr(dateEndId+1);
    // year = stoi(datestr.substr(dateEndId+1,datestr.size()-dateEndId-1));
}

void Date::print_date(string format){
    // TODO: Complete me!
    cout << get_date(format);
    
}

string Date::get_date(string format){
    // TODO: Complete me!
    if(format == "Month D, YYYY"){
        return month + " " + day + ", " + year;
    }
    else{
        return to_string(convertMonthStringToInt(month)) + "/" + day + "/" + year;
    }
}


bool Date::operator==(const Date& rhs){
    return (month == rhs.month) && (day == rhs.day) && (year == rhs.year);
}

bool Date::operator!=(const Date& rhs){
    return (month != rhs.month) || (day != rhs.day) || (year != rhs.year);
}
