#include <iostream>
#include <vector>
using namespace std;

/* ================== Person ================== */
class Person {
protected:
    int id;
    string name;
    int age;

public:
    Person(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }
};

/* ================== Patient ================== */
class Patient : public Person {
private:
    string disease;

public:
    Patient(int i, string n, int a, string d)
        : Person(i, n, a) {
        disease = d;
    }

    void show() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }
};

/* ================== Doctor ================== */
class Doctor : public Person {
private:
    string specialty;

public:
    Doctor(int i, string n, int a, string s)
        : Person(i, n, a) {
        specialty = s;
    }

    void show() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Specialty: " << specialty << endl;
    }
};

/* ================== Appointment ================== */
class Appointment {
private:
    Patient* patient;
    Doctor* doctor;

public:
    Appointment(Patient* p, Doctor* d) {
        patient = p;
        doctor = d;
    }

    void show() {
        cout << "Patient: " << patient->getName() << endl;
        cout << "Doctor: " << doctor->getName() << endl;
    }
};

/* ================== Hospital ================== */
class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    void addPatient() {
        int id, age;
        string name, disease;

        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;

        patients.push_back(Patient(id, name, age, disease));
        cout << "Patient added successfully ✔\n";
    }

    void addDoctor() {
        int id, age;
        string name, specialty;

        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Specialty: ";
        cin >> specialty;

        doctors.push_back(Doctor(id, name, age, specialty));
        cout << "Doctor added successfully ✔\n";
    }

    void showPatients() {
        if (patients.empty()) {
            cout << "No patients found ❌\n";
            return;
        }

        for (int i = 0; i < patients.size(); i++) {
            cout << "----- Patient " << i << " -----\n";
            patients[i].show();
        }
    }

    void showDoctors() {
        if (doctors.empty()) {
            cout << "No doctors found ❌\n";
            return;
        }

        for (int i = 0; i < doctors.size(); i++) {
            cout << "----- Doctor " << i << " -----\n";
            doctors[i].show();
        }
    }

    void makeAppointment() {
        if (patients.empty() || doctors.empty()) {
            cout << "Add patients and doctors first ❌\n";
            return;
        }

        int pIndex, dIndex;

        showPatients();
        cout << "Choose Patient Index: ";
        cin >> pIndex;

        showDoctors();
        cout << "Choose Doctor Index: ";
        cin >> dIndex;

        appointments.push_back(
            Appointment(&patients[pIndex], &doctors[dIndex])
        );

        cout << "Appointment booked successfully ✔\n";
    }

    void showAppointments() {
        if (appointments.empty()) {
            cout << "No appointments found ❌\n";
            return;
        }

        for (int i = 0; i < appointments.size(); i++) {
            cout << "----- Appointment " << i + 1 << " -----\n";
            appointments[i].show();
        }
    }
};

/* ================== main ================== */
int main() {
    Hospital hospital;
    int choice;

    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Show Patients\n";
        cout << "4. Show Doctors\n";
        cout << "5. Make Appointment\n";
        cout << "6. Show Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.addDoctor();
            break;
        case 3:
            hospital.showPatients();
            break;
        case 4:
            hospital.showDoctors();
            break;
        case 5:
            hospital.makeAppointment();
            break;
        case 6:
            hospital.showAppointments();
            break;
        case 0:
            cout << "System Closed 👋\n";
            break;
        default:
            cout << "Invalid choice ❌\n";
        }

    } while (choice != 0);

    return 0;
}