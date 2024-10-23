#pragma once
#ifndef PERSON_H // Check if PERSON_H is not defined
#define PERSON_H // Define PERSON_H
#include "Address.h"
#include <fstream>
#include <iomanip>

class Person
{ 
private:
	int ID;
	string First_Name;
	string Last_Name;
	string Full_Number1;
	string Full_Number2;
	string Email;
	string Gender;
	string Birth_Day;
	string classification;
	bool fav;

public:
	Address* address; // we use Aggregation instead of inheritence beacuse the relatio is like has a
	static int counter;
	Person();
	void set_id(int);
	int get_id();
	void storage();
	void set_Firist_Name(string);
	string get_Firist_Name() const;
	void set_Last_Name(string);
	string get_Last_Name() const;
	void set_Email(string);
	string get_Email() const;
	void set_Gender(string);
	string get_Gender() const;
	void set_Birith_Day(string);
	string get_Birith_day() const;
	void set_number1(string);
	string get_number1()const;
	void set_fav(int);
	int get_fav() const;
	void set_classification(string);
	string get_classification()const;
	void set_number2(string Full_Number2);
	string get_number2() const;
	void Display();
};
#endif // End of include guard
