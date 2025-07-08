#include <iostream>
#include <limits>
#include "Hospital.h"
using namespace std;

int main()
{
    Hospital hospital;
    int choice, pid;

    while (true)
    {
        cout << "\n============================\n";
        cout << " HOSPITAL PATIENT SYSTEM\n";
        cout << "============================\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. View All Patients\n";
        cout << "5. Exit\n";
        cout << "============================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            cout << "Enter Patient ID to delete: ";
            while (!(cin >> pid))
            {
                cout << "Invalid input. Please enter a valid integer for ID: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            hospital.deletePatient(pid);
            break;
        case 3:
            cout << "Enter Patient ID to search: ";
            while (!(cin >> pid))
            {
                cout << "Invalid input. Please enter a valid integer for ID: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            hospital.searchPatient(pid);
            break;
        case 4:
            hospital.displayAllPatients();
            break;
        case 5:
            cout << "Exiting Program. Stay Safe!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
