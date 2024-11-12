#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Fee {
private:
    float totalFee;
    float feePaid;

public:
    Fee(float totalFee) : totalFee(totalFee), feePaid(0) {}

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
        cout << "Total Fee: " << totalFee << "\nFee Paid: " << feePaid << "\nRemaining Balance: " << totalFee - feePaid << endl;
    }
};

class Student {
protected:
    string name;
    long long int rollNumber;
    Fee fee;
    static int totalStudents;

public:
    Student() : name(""), rollNumber(0), fee(0.0) { totalStudents++; }
    Student(string n, long long int r, float totalFee) : name(n), rollNumber(r), fee(totalFee) { totalStudents++; }

    string getName() const { return name; }
    long long int getRollNumber() const { return rollNumber; }
    static int getTotalStudent() { return totalStudents; }

    void makeFeePayment(float amount) { fee.makePayment(amount); }

    // Function Overloading: Overloaded displayData() to show different outputs
    void displayData() const {
        cout << "Student Info: \n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
        fee.displayFeeDetails();
    }

    void displayData(bool showFee) const {
        cout << "Student Info: \n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
        if (showFee) {
            fee.displayFeeDetails();
        }
    }

    ~Student() { totalStudents--; }
};

int Student::totalStudents = 0;

class Course {
protected:
    string courseName;
    int courseCode;
    static int totalCourses;

public:
    Course(string cn, int cc) : courseName(cn), courseCode(cc) { totalCourses++; }

    string getCourseName() const { return courseName; }
    int getCourseCode() const { return courseCode; }
    static int getTotalCourses() { return totalCourses; }

    virtual void displayCourseDetails() const {
        cout << "Course Name: " << courseName << "\nCourse Code: " << courseCode << endl;
    }

    ~Course() { totalCourses--; }
};

int Course::totalCourses = 0;

// Undergraduate class derived from Student (Inheritance example)
class Undergraduate : public Student {
private:
    string major;

public:
    Undergraduate(string n, long long int r, float totalFee, string m)
        : Student(n, r, totalFee), major(m) {}

    void displayData() const {
        cout << "Undergraduate Student Info:\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nMajor: " << major << endl;
        fee.displayFeeDetails();
    }
};

// Graduate class derived from Student (Inheritance example)
class Graduate : public Student {
private:
    string researchTopic;

public:
    Graduate(string n, long long int r, float totalFee, string rt)
        : Student(n, r, totalFee), researchTopic(rt) {}

    void displayData() const {
        cout << "Graduate Student Info:\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nResearch Topic: " << researchTopic << endl;
        fee.displayFeeDetails();
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

    if (choice == 1) {
        cout << "Major: ";
        cin >> major;
        Undergraduate ug(sName, sRollNumber, sTotalFee, major);
        ug.displayData();
    } else if (choice == 2) {
        cout << "Research Topic: ";
        cin >> researchTopic;
        Graduate grad(sName, sRollNumber, sTotalFee, researchTopic);
        grad.displayData();
    } else {
        cout << "Invalid choice." << endl;
    }

    cout << "\nTotal Students: " << Student::getTotalStudent() << endl;
    cout << "Total Courses: " << Course::getTotalCourses() << endl;

    return 0;
}
