#include "Patient.h"
#include <limits>

Patient::Patient(int pid, string pname, int page, string pdisease) {
    id = pid;
    name = pname;
    age = page;
    disease = pdisease;
    next = NULL;
}
