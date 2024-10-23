#pragma once
#ifndef ADDRESS_H 
#define ADDRESS_H 
#include <string>
#include <iostream>

using namespace std;

class Address
{
private:
	string country;
	string Government;
	string City;
	string Street_Number;
public:
	Address();
	void storage();
	void set_country(string);
	string get_country() const;
	void set_Government(string);
	string get_Government() const;
	void set_City(string);
	string get_City() const;
	void set_street_Number(string);
	string get_street_Number() const;
	//void Display();we will not use it beacause we want to display in xls file *_*
};
#endif