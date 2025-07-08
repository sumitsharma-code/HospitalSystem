#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"


class Hospital {
private:
    Patient* head;

public:
    Hospital();
    ~Hospital();
    void addPatient();
    void deletePatient(int pid);
    void searchPatient(int pid);
    void displayAllPatients();
};

#endif