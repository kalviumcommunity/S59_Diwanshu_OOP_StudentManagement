#include <vector>
#include <string>
#include <iostream>

using namespace std;

// FeeManager class (SRP: Manages fee-related operations)
class FeeManager {
private:
    float totalFee;
    float feePaid;

public:
    FeeManager(float totalFee) : totalFee(totalFee), feePaid(0) {}

    float getTotalFee() const { return totalFee; }
    float getFeePaid() const { return feePaid; }

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

// Abstract base class for Students (SRP: Manages student details)
class Student {
protected:
    string name;
    long long int rollNumber;
    FeeManager feeManager;
    static int totalStudents;

public:
    Student(string n, long long int r, float totalFee) 
        : name(n), rollNumber(r), feeManager(totalFee) {
        totalStudents++;
    }

    virtual ~Student() { totalStudents--; }

    string getName() const { return name; }
    long long int getRollNumber() const { return rollNumber; }

    static int getTotalStudent() { return totalStudents; }

    void makeFeePayment(float amount) { feeManager.makePayment(amount); }

    // Pure virtual function to enforce overriding in derived classes
    virtual void displayData() const = 0;

    void displayFeeDetails() const { feeManager.displayFeeDetails(); }
};

int Student::totalStudents = 0;

// Undergraduate class (SRP: Handles undergraduate-specific details)
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

// Graduate class (SRP: Handles graduate-specific details)
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

int main() {
    string sName, major, researchTopic;
    long long int sRollNumber;
    float sTotalFee;
    int choice;

    cout << "Choose type of student:\n1. Undergraduate\n2. Graduate\n";
    cin >> choice;

    cout << "Enter details:\n";
    cout << "Name: ";
    cin >> sName;
    cout << "Roll Number: ";
    cin >> sRollNumber;
    cout << "Total Fee: ";
    cin >> sTotalFee;

    Student* student = nullptr;

    if (choice == 1) {
        cout << "Major: ";
        cin >> major;
        student = new Undergraduate(sName, sRollNumber, sTotalFee, major);
    } else if (choice == 2) {
        cout << "Research Topic: ";
        cin >> researchTopic;
        student = new Graduate(sName, sRollNumber, sTotalFee, researchTopic);
    } else {
        cout << "Invalid choice." << endl;
    }

    if (student) {
        student->displayData();  
        student->makeFeePayment(500);  
        student->displayFeeDetails();
        delete student;  
    }

    cout << "\nTotal Students: " << Student::getTotalStudent() << endl;

    return 0;
}
