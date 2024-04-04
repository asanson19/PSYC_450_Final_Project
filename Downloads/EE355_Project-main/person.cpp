
#include "person.h"
#include <vector>
#include <algorithm>

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
}


Person::Person(string f_name, string l_name, string b_date,  string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name=f_name;
    this->l_name=l_name;
    this->birthdate=new Date(b_date);
   //string emailtype=Email.type();
   //need to extract email type and actual email from the string

    string phone_type;
    string phone_number;
    //copying supriyas person code lol
    // Extract phone type and number from the line
    size_t pos = phone.find_first_of("(");
    phone_type = phone.substr(pos + 1, phone.find_first_of(")") - pos - 1);
    pos = phone.find_first_of("0123456789");
    phone_number = phone.substr(pos);

    string email_type;
    string email_address;

    // Extract email type and address from the line
    pos = email.find_first_of("(");
    email_type = email.substr(pos + 1, email.find_first_of(")") - pos - 1);
    int index=email_type.size();
    //need to find size of email_type string, then increment by 1, that will give us email only
   // pos = email.find_first_of("<");
    email_address = email.substr(index+3);

    this->email=new Email(email_type,email_address);
    this->phone=new Phone(phone_type,phone_number);

}

Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    cin>>type;
    cout << "Email address: ";
    cin>>temp;
    email=new Email(type,temp);

    cout << "Type of phone number: ";
    cin>>type;
    cout << "Phone number: ";
    cin>>temp;
    phone=new Phone(type,temp);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    ifstream file(filename);
    if (file.is_open()) {
        // Read first and last name
        getline(file, f_name);
        getline(file, l_name);

        // Read birthdate
        string b_date;
        getline(file, b_date);
        birthdate = new Date(b_date);

        // Read phone number and its type
        string phone_line;
        getline(file, phone_line);
        string phone_type;
        string phone_number;

        // Extract phone type and number from the line
        size_t pos = phone_line.find_first_of("(");
        phone_type = phone_line.substr(pos + 1, phone_line.find_first_of(")") - pos - 1);
        pos = phone_line.find_first_of("0123456789");
        phone_number = phone_line.substr(pos);

        // Remove any '-' characters from phone number
        //actually we dont want to erase them
        //phone_number.erase(std::remove_if(phone_number.begin(), phone_number.end(), ::isdigit), phone_number.end());

        // Set phone number
        phone = new Phone(phone_type, phone_number);

        // Read email address and its type
        string email_line;
        getline(file, email_line);
        string email_type;
        string email_address;

        // Extract email type and address from the line
        pos = email_line.find_first_of("(");
        email_type = email_line.substr(pos + 1, email_line.find_first_of(")") - pos - 1);
        pos = email_line.find_first_of("<");
        email_address = email_line.substr(pos + 1, email_line.find_first_of(">") - pos - 1);

        // Set email address
        email = new Email(email_type, email_address);
    }
    file.close();

}

bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return (f_name == rhs.f_name) && (l_name == rhs.l_name) && (birthdate == rhs.birthdate);
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return (f_name != rhs.f_name) || (l_name != rhs.l_name) || (birthdate == rhs.birthdate);

}



void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    cout<<endl;
    cout << "Phone ";
    phone->print();
    cout << "Email ";
    email->print();
    cout << endl;
}
