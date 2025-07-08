#include <iostream>
#include <limits>
#include "Hospital.h"

using namespace std;

Hospital::Hospital() {
    head = NULL;
}

Hospital::~Hospital() {
    while (head) {
        Patient* temp = head;
        head = head->next;
        delete temp;
    }
}

void Hospital::addPatient() {
    int id, age;
    string name, disease;

    cout << "Enter Patient ID: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Invalid input. Please enter a valid positive integer for Age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, disease);

    Patient* newPatient = new Patient(id, name, age, disease);

    if (!head) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newPatient;
    }

    cout << "Patient record added successfully!\n";
}

void Hospital::deletePatient(int pid) {
    if (!head) {
        cout << "No patient records found.\n";
        return;
    }

    Patient* temp = head;
    Patient* prev = NULL;

    while (temp && temp->id != pid) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Patient with ID " << pid << " not found.\n";
        return;
    }

    if (!prev) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Patient record deleted.\n";
}

void Hospital::searchPatient(int pid) {
    Patient* temp = head;

    while (temp) {
        if (temp->id == pid) {
            cout << "Patient Found:\n";
            cout << "ID: " << temp->id << "\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "Disease: " << temp->disease << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Patient with ID " << pid << " not found.\n";
}

void Hospital::displayAllPatients() {
    if (!head) {
        cout << "No patient records available.\n";
        return;
    }

    Patient* temp = head;
    cout << "\nAll Patient Records:\n";
    while (temp) {
        cout << "-----------------------------\n";
        cout << "ID: " << temp->id << "\n";
        cout << "Name: " << temp->name << "\n";
        cout << "Age: " << temp->age << "\n";
        cout << "Disease: " << temp->disease << "\n";
        temp = temp->next;
    }
    cout << "-----------------------------\n";
}