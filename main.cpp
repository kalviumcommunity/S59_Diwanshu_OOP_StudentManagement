#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Fee
{
private:
    float totalFee;
    float feePaid;

public:
    Fee(float totalFee) : totalFee(totalFee), feePaid(0) {}

    void makePayment(float amount)
    {
        if (amount > 0 && feePaid + amount <= totalFee)
        {
            feePaid += amount;
            cout << "Payment of " << amount << " made successfully." << endl;
        }
        else
        {
            cout << "Invalid payment amount. Please check the balance." << endl;
        }
    }

    void displayFeeDetails()
    {
        cout << "Total Fee: " << totalFee << "\nFee Paid: " << feePaid << "\nRemaining Balance: " << totalFee - feePaid << endl;
    }
};

class Student
{
private:
    string name;
    long long int rollNumber;
    Fee fee;
    static int studentNumber;

public:
    Student() : name(""), rollNumber(0), fee(0.0)
    {
        studentNumber++;
    }
    Student(string n, long long int r, float totalFee) : name(n), rollNumber(r), fee(totalFee)
    {
        studentNumber++;
    }

    static int getTotalStudent()
    {
        return studentNumber;
    }
    Student &updateDetails(string name, long long int rollNumber)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        return *this;
    }

    void makeFeePayment(float amount)
    {
        fee.makePayment(amount);
    }

    void displayData()
    {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
        fee.displayFeeDetails();
    }
    ~Student()
    {
        studentNumber--;
    }
};

int Student::studentNumber = 0;

class Course
{
private:
    string courseName;
    int courseCode;

public:
    Course(string cn, int cc) : courseName(cn), courseCode(cc) {}

    void displayCourseDetails()
    {
        cout << "Course Name: " << courseName << "\nCourse Code: " << courseCode << endl;
    }

    void updateCourseDetails(string cn, int cc)
    {
        courseName = cn;
        courseCode = cc;
    }
};

int main()
{
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        long long int rollNumber;
        float totalFee;

        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Roll Number: ";
        cin >> rollNumber;
        cout << "Total Fee: ";
        cin >> totalFee;

        students[i] = Student(name, rollNumber, totalFee);
    }

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nDetails of student " << i + 1 << ":\n";
        students[i].displayData();

        float payment;
        cout << "Enter payment amount for student " << i + 1 << ": ";
        cin >> payment;
        students[i].makeFeePayment(payment);

        students[i].displayData();
    }

    cout << "Total Students: " << Student::getTotalStudent() << endl;

    delete[] students;

    return 0;
}
