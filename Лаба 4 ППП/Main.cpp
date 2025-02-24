#include <iostream>
#include "Functions.h"

using namespace std;

int main() {
    int choice;
    
    do {
        cout << "Select a program to run:\n";
        cout << "1. Payroll System\n";
        cout << "2. Luggage Compartment System\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1:
                menuPayrollSystem();
                break;
            case 2:
                menuLuggageSystem();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}