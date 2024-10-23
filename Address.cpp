#include "Address.h"

Address::Address() {
    
}

void Address::storage(){
    cout << "\033[1;35m5.Please Enter Country : \033[0m";
    getline(cin, country);
    cout << endl;
    cout << "\033[1;35m5.Please Enter Government : \033[0m";
    getline(cin, Government);
    cout << endl;
    cout << "\033[1;35m5.Please Enter City : \033[0m";
    getline(cin, City);
    cout << endl;
    cout << "\033[1;35m5.Please Enter street-number : \033[0m";
    getline(cin, Street_Number);
    cout << endl;
}

void Address::set_country(string country)
{
    this->country = country;
}

string Address::get_country() const
{
    return country;
}

void Address::set_Government(string Government)
{
    this->Government = Government;
}

string Address::get_Government() const
{
    return Government;
}

void Address::set_City(string City)
{
    this->City = City;
}

string Address::get_City() const
{
    return City;
}

void Address::set_street_Number(string Street_Number)
{
    this->Street_Number = Street_Number;
}

string Address::get_street_Number() const
{
    return Street_Number;
}

/*void Address::Display()
{
    cout << "\033[1;32m1.Country : " << country << "\033[1;32m1. | " << "\033[1;32m1.Government : " << Government << "\033[1;32m1. | " << "\033[1;32m1.City : " << City << " | " << "\033[1;32m1.Street_Number : " << Street_Number << "\033[1;32m1. | " << endl << endl;
}
*/
