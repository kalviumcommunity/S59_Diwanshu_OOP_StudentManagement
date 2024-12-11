#include <iostream>
#include <string>

using namespace std;

// Base FeeManager class (No changes)
class FeeManager {
private:
    float totalFee;
    float feePaid;

public:
    FeeManager(float totalFee) : totalFee(totalFee), feePaid(0) {}

    void makePayment(float amount) {
        if (amount > 0 && feePaid + amount <= totalFee) {
            feePaid += amount;
            cout << "Payment of " << amount << " made successfully." << endl;
        } else {
            cout << "Invalid payment amount. Please check the balance." << endl;
        }
    }

    void displayFeeDetails() const {
        cout << "Total Fee: " << totalFee 
             << "\nFee Paid: " << feePaid 
             << "\nRemaining Balance: " << totalFee - feePaid 
             << endl;
    }
};

// Base Student class (No changes)
class Student {
protected:
    string name;
    long long int rollNumber;
    FeeManager feeManager;

public:
    Student(string n, long long int r, float totalFee)
        : name(n), rollNumber(r), feeManager(totalFee) {}

    virtual void displayData() const = 0;
    void makeFeePayment(float amount) { feeManager.makePayment(amount); }
    void displayFeeDetails() const { feeManager.displayFeeDetails(); }
};

// Existing Undergraduate and Graduate classes (No changes)
class Undergraduate : public Student {
private:
    string major;

public:
    Undergraduate(string n, long long int r, float totalFee, string m)
        : Student(n, r, totalFee), major(m) {}

    void displayData() const override {
        cout << "Undergraduate Student Info:\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber 
             << "\nMajor: " << major << endl;
        displayFeeDetails();
    }
};

class Graduate : public Student {
private:
    string researchTopic;

public:
    Graduate(string n, long long int r, float totalFee, string rt)
        : Student(n, r, totalFee), researchTopic(rt) {}

    void displayData() const override {
        cout << "Graduate Student Info:\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber 
             << "\nResearch Topic: " << researchTopic << endl;
        displayFeeDetails();
    }
};

// New PartTimeStudent class (Extending functionality without modifying existing classes)
class PartTimeStudent : public Student {
private:
    int hoursPerWeek;

public:
    PartTimeStudent(string n, long long int r, float totalFee, int hours)
        : Student(n, r, totalFee), hoursPerWeek(hours) {}

    void displayData() const override {
        cout << "Part-Time Student Info:\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber 
             << "\nHours Per Week: " << hoursPerWeek << endl;
        displayFeeDetails();
    }
};

int main() {
    Student* student = nullptr;
    string sName;
    long long int sRollNumber;
    float sTotalFee;
    int choice;

    cout << "Choose type of student:\n1. Undergraduate\n2. Graduate\n3. Part-Time\n";
    cin >> choice;

    cout << "Enter Name: ";
    cin >> sName;
    cout << "Enter Roll Number: ";
    cin >> sRollNumber;
    cout << "Enter Total Fee: ";
    cin >> sTotalFee;

    if (choice == 1) {
        string major;
        cout << "Enter Major: ";
        cin >> major;
        student = new Undergraduate(sName, sRollNumber, sTotalFee, major);
    } else if (choice == 2) {
        string researchTopic;
        cout << "Enter Research Topic: ";
        cin >> researchTopic;
        student = new Graduate(sName, sRollNumber, sTotalFee, researchTopic);
    } else if (choice == 3) {
        int hoursPerWeek;
        cout << "Enter Hours Per Week: ";
        cin >> hoursPerWeek;
        student = new PartTimeStudent(sName, sRollNumber, sTotalFee, hoursPerWeek);
    } else {
        cout << "Invalid choice." << endl;
    }

    if (student) {
        student->displayData();
        student->makeFeePayment(500);  // Example payment
        delete student;  // Clean up memory
    }

    return 0;
}
