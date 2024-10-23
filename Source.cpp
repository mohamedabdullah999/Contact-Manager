#include <iostream>
#include "Person.h"
#include "Array.h"
#include "Get_Contact.h"
#include "Address.h"
#include <windows.h>

using namespace std;

int Computer_Decision;

void say_hello_to_user() {
    cout << "\t\t\t\t\t==========================\n";
    cout << "\033[32mHello To Contact Manager *__*\n \033[0m" << endl;
    cout << "\t\t\t\t\t==========================\n";
}

int main() {

    Get_Contact<Person> p;

    do {
        p.menue();
        cout << "\t\t\t\t\t===========================\n";
        cout << "\t\t\t\t\t\033[1;33mPlease choose your decision\033[0m\n";
        cout << "\t\t\t\t\t===========================\n\n";
        cout << "\033[1;31mYour Decision -> \033[0m";
        cin >> Computer_Decision;
        cin.ignore();

        switch (Computer_Decision) {
        case 1: {
            system("cls");
            p.Display_all_contacts();
            break;
        }
        case 2: {
            system("cls");
            p.Add_new_contact();
            break;
        }
        case 3: {
            system("cls");
            cout << "Please Enter The number that you want to search about: ";
            string num;
            getline(cin, num);
            p.search_with_telephone_Number(num);
            break;
        }

        case 4: {
            system("cls");
            p.save_to_DB();
            break;
        }
        case 5: {
            system("cls");
            string lastname;
            cout << "Enter the last name you want to search about : ";
            getline(cin, lastname);
            p.search_with_second_name(lastname);
            break;
        }

        case 6: {
            system("cls");
            string firstname;
            cout << "Enter the first name you want to search about : ";
            getline(cin, firstname);
            p.search_with_First_name(firstname);
            break;
        }

        case 7: {
            system("cls");
            int id;
            cout << "Enter the id if contact you want to update : ";
            cin >> id;
            id--;
            cin.ignore();
            p.update_contact(id);
            break;
        }

        case 8:
            system("cls");
            p.delete_contact();
            break;

        case 10:
            system("cls");
            p.print_all_FAV();
            break;

        case 11: {
            system("cls");
            string s;
            cout << "Please enter the classification you want to search about : ";
            getline(cin, s);
            p.search_with_classification(s);
            break;
        }

        case 12: {
            system("cls");
            p.reverse();
            break;
        }
        case 13: {
            system("cls");
            p.load_file();
            break;
        }
        case 9: {
            system("cls");
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            system("cls");
            cout << "Invalid option, please try again." << endl;
            break;
        }
        }

    } while (Computer_Decision != 9);

    return 0;
}
