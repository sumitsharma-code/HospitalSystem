#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;
    Patient* next;

    Patient(int pid, string pname, int page, string pdisease);
};

#endif