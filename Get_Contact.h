#ifndef GET_CONTACT_H 
#define GET_CONTACT_H 
#pragma once
#include "Array.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

template<class T>
class Get_Contact {
private:
    Array <T> arr;
    bool flag_print = 0 , display = 0;

public:

    Get_Contact() {
        cout << "\t\t\t\t\t==========================\n";
        cout << "\t\t\t\t\t\033[32mHello To Contact Manager \n \033[0m";
        cout << "\t\t\t\t\t==========================\n\n";
    }

    void menue() {
        cout << "\t\t\t\t\t\033[1;32m1.Display all Contacts\n\t\t\t\t\t2.Add new contact\033[0m\n";
        cout << "\t\t\t\t\t\033[1;33m3.Search with telephone number\n\t\t\t\t\t4.Save to Database\t\t\t\t\t\033[0m\n";
        cout << "\t\t\t\t\t\033[1;35m5.search with the last name\n\t\t\t\t\t6.Search with first name\033[0m\n";
        cout << "\t\t\t\t\t\033[32m7.Update contact\n\t\t\t\t\t8.Delete contact\033[0m\n";
        cout << "\t\t\t\t\t\033[1;31m9.Exit\n\t\t\t\t\t10.Print all FAV contacts\033[0m\n";
        cout << "\t\t\t\t\t\033[1;32m11.search with classification\n\t\t\t\t\t12.Reverse contacts\033[0m\n";
        cout << "\t\t\t\t\t\033[1;32m13.Load File\033[0m\n\n";
    }

    void print_all_FAV() {
        cout << "WARNING : we get all FAV contacts from the database to terminal........\n" << endl;
        for (int i = 0; i < arr.getSize(); i++) {
            if (arr[i].get_fav() == 1) {
                arr[i].Display();
            }
        }
    }

    void Display_all_contacts(){
        for (int i = 0; i < arr.getSize(); i++) {
            arr[i].Display();
        }
    }

    void save_to_DB() {
        cout << "Enter name of database file : ";
        string file;
        getline(cin, file);
        ofstream out;
        out.open(file);

        if (flag_print == 0) {
            out << setw(5) << left << "ID" << setw(20) << left << "First Name" << setw(20) << left << "Last Name" << setw(20) << left <<
            "Classification" << setw(10) << left << "FAV" << setw(20) << left << "Address" << setw(30) << left << "Telephone" << setw(23)
            << left << "Email" << setw(20) << left << "Birith date" << setw(10) << left << "Gender" << setw(20) << left << "City" << endl;
            out << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            flag_print = 1;
        }

        for (int i = 0; i < arr.getSize(); i++) {

            out << setw(5) << left << arr[i].get_id() << setw(20) << left << arr[i].get_Firist_Name() << setw(20) << left << arr[i].get_Last_Name() << setw(20) << left
            << arr[i].get_classification() << setw(10) << left;

            arr[i].get_fav()?out << "Fav" : out << "non-fav";
           
            out << setw(20) << left << arr[i].address->get_street_Number() << setw(30) << left << arr[i].get_number1() + ',' + arr[i].get_number2() << setw(23) << left
                << arr[i].get_Email() << setw(20) << left << arr[i].get_Birith_day() << setw(10) << left << arr[i].get_Gender() << setw(20) << left << arr[i].address->get_City() << endl;
                
            out << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        out.close();
    }

    void load_file() {
        cout << "Enter name of the file of DB please: ";
        string file_name;
        getline(cin, file_name); 
        cout << '\n';

        ifstream in(file_name); 

        if (!in) {
            cout << "Error: Cannot open file " << file_name << endl;
            return;
        }

        string firstName, lastName, classification, fav, streetNumber, phoneNumber1, phoneNumber2, email, birthDate, gender, city;
        int id;
        while (in >> id >> firstName >> lastName >> classification >> fav >> streetNumber >> phoneNumber1 >> phoneNumber2 >> email >> birthDate >> gender >> city) {
            cout << "Reading contact: " << firstName << " " << lastName << endl; // التحقق من قراءة الأسماء

           
            Person n;

            n.set_id(id);
            n.set_Firist_Name(firstName);
            n.set_Last_Name(lastName);
            n.set_classification(classification);

            if (fav == "FAV") {
                n.set_fav(1); 
            }
            else {
                n.set_fav(0); 
            }

            
            n.address = new Address();
            n.address->set_street_Number(streetNumber);
            n.set_number1(phoneNumber1);
            n.set_number2(phoneNumber2);
            n.set_Email(email);
            n.set_Birith_Day(birthDate);
            n.set_Gender(gender);
            n.address->set_City(city);

            
            arr.Append(n);

            cout << "Contact added successfully.\n"; 
        }

        in.close();

        cout << "Contacts loaded successfully from file: " << file_name << endl;
    }



    void Add_new_contact() {
        int flag;
        cout << "=============================================================\n";
        cout << "\033[32mYou want insert this contact in 1.specfic index or 2.respectively\033[0m ";
        cin >> flag;
        cout << "=====================================================\n";
        cout << endl;
        if (flag == 1) {
            cout << "\033[1;35m5.Please Give me the index you want to Add the contact there\033[0m ";
            int index; cin >> index;
            cout << endl;
            T p;
            p.storage();
            arr.Insert(p, index);
            //return;
        }
        else {
            T p;
            p.storage();
            arr.Append(p);
        }
    }

    void search_with_telephone_Number(const string & num){
        bool flag = 0; // to check there is content was printed?
        for (int i = 0; i < arr.getSize(); i++) {
            if (arr[i].get_number1() == num || arr[i].get_number2() == num) {
                arr[i].Display();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Sorry there isnnot any contact with number of this number......\n";
        }
    }

    void search_with_First_name(const string & first_name) {
        bool flag = 0; // to check there is content was printed?
        for (int i = 0; i < arr.getSize(); i++) {
            if (arr[i].get_Firist_Name() == first_name) {
                arr[i].Display();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Sorry there isnnot any contact with first name......\n";
        }
    }

    void search_with_second_name(const string& Last_name){
        bool flag = 0; // to check there is content was printed?
        for (int i = 0; i < arr.getSize(); i++) {
            if (arr[i].get_Last_Name() == Last_name) {
                arr[i].Display();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Sorry there isnnot any contact with Last name......\n";
        }
    }

    void search_with_classification(const string& classificaion) {
        bool flag = 0; // to check there is content was printed?
        for (int i = 0; i < arr.getSize(); i++) {
            if (arr[i].get_classification() == classificaion) {
                arr[i].Display();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Sorry there isnnot any contact with classification......\n";
        }
    }

    void update_contact(int idx) {
        cout << "\t\t\t\tWhat is the type of update you want ?\n";
        cout << "\t\t\t\tN.Name?\t\t\t\tt.Telephone Number?\n";
        cout << "\t\t\t\tE.Email\t\t\t\tG.Gender\n";
        cout << "\t\t\t\tB.Birth Day\t\t\t\tC.country\n";
        cout << "\t\t\t\tO.Government\t\t\t\ts.Street Nmber\n";
        char decision; cin >> decision;
        cin.ignore();
        Person m = arr[idx];
        if (decision == 'N') {
            string first, last;
            cout << "Please Enter new first name : ";
            getline(cin, first);
            cout << "Please enter new last name : ";
            getline(cin, last);
            m.set_Firist_Name(first);
            m.set_Last_Name(last);
            arr.set(idx, m);
        }
        else if (decision == 't') {
            cout << "Please Enter new telephone number : ";
            string number;
            getline(cin, number);
            m.set_number1(number);
            arr.set(idx, m);
        }
        else if (decision == 'E') {
            cout << "Please Enter new telephone number : ";
            string email;
            getline(cin, email);
            m.set_Email(email);
            arr.set(idx, m);
        }
        else if (decision == 'G') {
            cout << "Please Enter new Gender : ";
            string gender;
            getline(cin, gender);
            m.set_Gender(gender);
            arr.set(idx, m);
        }
        else  if (decision == 'B') {
            cout << "Please Enter new Birith_Date : ";
            string birith_date;
            getline(cin, birith_date);
            m.set_Birith_Day(birith_date);
            arr.set(idx, m);
        }
        else if (decision == 'C') {
            cout << "Please Enter new country : ";
            string country;
            getline(cin, country);
            m.address->set_country(country);
            arr.set(idx, m);
        }
        else if (decision == 'O') {
            cout << "Please Enter new Government : ";
            string Government;
            getline(cin, Government);
            m.address->set_Government(Government);
            arr.set(idx, m);
        }
        else if (decision == 's') {
            cout << "Please enter new street number : ";
            string street_number;
            getline(cin, street_number);
            m.address->set_street_Number(street_number);
            arr.set(idx, m);
        }
    }

    void delete_contact() {
        cout << "If you want to remove the last contact, choose \"1\", else choose \"2\": ";
        int deleteOption;
        cin >> deleteOption;
        cin.ignore();
        cout << endl;
        if (deleteOption == 1) {
            arr.Remove();
        }
        else {
            cout << "Enter index you want to delete : ";
            int idx;
            cin >> idx;
            idx--;
            arr.Delete(idx);
        }
        cout << "Contact deleted successfully.\n";
        cin.ignore();
    }

    void reverse() {
        cout << "Reversing done........\n\n";
        arr.reversearr();
    }

    void Exit() {
        cout << "===============Thanks for using my contact manager=====================\n";
    }
};
#endif
