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

    
    float getTotalFee() const
    {
        return totalFee;
    }

   
    float getFeePaid() const
    {
        return feePaid;
    }

  
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
    static int totalStudents;

public:
  
    Student() : name(""), rollNumber(0), fee(0.0)
    {
        totalStudents++;
    }


    Student(string n, long long int r, float totalFee) : name(n), rollNumber(r), fee(totalFee)
    {
        totalStudents++;
    }

 
    string getName() const
    {
        return name;
    }

    long long int getRollNumber() const
    {
        return rollNumber;
    }

  
    void setName(string newName)
    {
        name = newName;
    }

   
    void setRollNumber(long long int newRollNumber)
    {
        rollNumber = newRollNumber;
    }

    static int getTotalStudent()
    {
        return totalStudents;
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
        totalStudents--;
    }
};

int Student::totalStudents = 0;

class Course
{
private:
    string courseName;
    int courseCode;
    static int totalCourses;

public:
   
    Course(string cn, int cc) : courseName(cn), courseCode(cc)
    {
        totalCourses++;
    }

  
    string getCourseName() const
    {
        return courseName;
    }

  
    int getCourseCode() const
    {
        return courseCode;
    }

    void setCourseName(string cn)
    {
        courseName = cn;
    }

   
    void setCourseCode(int cc)
    {
        courseCode = cc;
    }

    static int getTotalCourses()
    {
        return totalCourses;
    }

    void displayCourseDetails()
    {
        cout << "Course Name: " << courseName << "\nCourse Code: " << courseCode << endl;
    }

    ~Course()
    {
        totalCourses--;
    }
};

int Course::totalCourses = 0;

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
    cout << "Total Courses: " << Course::getTotalCourses() << endl;

    delete[] students;

    return 0;
}
