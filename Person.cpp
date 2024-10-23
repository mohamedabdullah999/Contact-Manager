#include "Person.h"
#include "Array.h"

int Person::counter = 0;

Person::Person():ID(0){
	First_Name = "";
	Last_Name = "";
	Full_Number1 = "";
	Full_Number2 = "";
	Birth_Day = "";
	classification = "";
	Email = "";
	Gender = "";
}

void Person::set_id(int ID) {
	this->ID = ID;
}


void Person::storage()
{
	cout << "\033[1;35mHEY.........\nNow the boot will ask you some qustions to coolect date about you..........\033[0m\n";
	counter++;
	this->ID = counter;
	cin.ignore();
	cout << "\033[1;35mPlease Enter Firist-Name :\033[0m";
	getline(cin, First_Name);
	cout << endl;
	cout << "\033[1;35mPlease Enter Last-Name :\033[0m ";
	getline(cin, Last_Name);
	cout << endl;
	cout << "\033[1;35mPlease Enter the first Full-Number : \033[0m";
	getline(cin, Full_Number1);
	cout << endl;
	cout << "\033[1;36mEnter the second full number: \033[0m";
	getline(cin, Full_Number2);
	cout << endl;
	cout << "\033[1;32mIs this contact a favorite? (press 1 for yes, 0 for no): \033[0m";
	cin >> fav;
	cout << endl;
	cin.ignore();
	cout << "\033[1;35mPlease enter the classification of the contact (family / work /...): \033[0m";
	getline(cin, classification);
	cout << endl;
	cout << "\033[1;35mPlease Enter Email : \033[0m";
	getline(cin, Email);
	cout << endl;
	cout << "\033[1;35mPlease Enter Gender : \033[0m";
	getline(cin, Gender);
	cout << endl;
	cout << "\033[1;35mPlease Enter Birith-Day : \033[0m";
	getline(cin, Birth_Day);
	cout << endl;
	Address* d = new Address();
	d->storage();
	this->address = d;
}

void Person::set_Firist_Name(string First_Name){
	this->First_Name = First_Name;
}

string Person::get_Firist_Name() const {
	return First_Name;
}

void Person::set_Last_Name(string Last_Name){
	this->Last_Name = Last_Name;
}

string Person::get_Last_Name() const {
	return Last_Name;
}

void Person::set_Email(string Email){
	this->Email = Email;
}

string Person::get_Email() const {
	return Email;
}

void Person::set_Gender(string Gender){
	this->Gender = Gender;
}

string Person::get_Gender() const {
	return Gender;
}

void Person::set_Birith_Day(string Birith_Day){
	this->Birth_Day = Birith_Day;
}

string Person::get_Birith_day() const {
	return Birth_Day;
}

void Person::set_number1(string Full_Number1){
	this->Full_Number1 = Full_Number1;
}

string Person::get_number1() const
{
	return Full_Number1;
}

int Person::get_id()
{
	return ID;
}

void Person::set_fav(int fav){
	this->fav = fav;
}

int Person::get_fav() const
{
	return fav;
}

void Person::set_classification(string classification){
	this->classification = classification;
}

string Person::get_classification() const
{
	return classification;
}

void Person::set_number2(string Full_Number2){
	this->Full_Number2 = Full_Number2;
}

string Person::get_number2() const
{
	return Full_Number2;
}

void Person::Display(){
	//cout << "=====================================================\n";
	cout << "ID : " << ID << endl << "First Name : " << get_Firist_Name() << endl << "Last Name : " << Last_Name << endl
    << "Classification : " << classification << endl << "Address : " << address->get_street_Number() << endl << "Telephone-1 : " << Full_Number1 << endl << 
	"Telephone-2 : " << Full_Number2 << endl <<	"Email : " << Email  << endl << "Birith date : " << get_Birith_day() << endl << "Gender : " << Gender << endl
	<< "City : " << address->get_City() << endl;
	fav ? cout << "FAV" : cout << "non-FAV";
	cout << '\n';
	cout << "=====================================================\n" << endl;
}
