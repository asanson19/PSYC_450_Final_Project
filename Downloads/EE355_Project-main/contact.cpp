#include "contact.h"
// TODO: Add needed libraries! 

Email::Email(string type_given, string given_email_addr){
    // TODO: Complete me!
    type = type_given;
    email_addr = given_email_addr;
    
}


void Email::set_contact(){
    // TODO: Do not change the prompts!

    cout << "Enter the type of email address: ";
    cin>>type;
    cout << "Enter email address: ";
    cin>>email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full"){
	    return "(" + type + "): " + email_addr;
    }
    else{
        return email_addr;

    }
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    this->type=type;
   string temp=num;
   if(temp.size()!=10){
    //case for there are dashes
        phone_num=temp;
   }
   else{
    //all characters squished together, need to put dashes
        phone_num=temp.substr(0,3)+'-'+temp.substr(3,3)+'-'+temp.substr(6);
   }
}

void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin>>type;
	cout << "Enter the phone number: ";
    cin>>phone_num;
}


string Phone::get_contact(string style){ 
    // TODO: Complete this method, get hint from Email 
    if (style=="full"){
        return "(" + type + "): " + phone_num;
    }
    else{
        return phone_num;
    }
}


void Phone::print() {
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

