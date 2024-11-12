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

    float getTotalFee() const { return totalFee; }
    float getFeePaid() const { return feePaid; }

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
    virtual void displayData()
    {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
        fee.displayFeeDetails();
    }

    ~Student() { totalStudents--; }
};

int Student::totalStudents = 0;

// Single Inheritance: UndergraduateStudent inherits from Student
class UndergraduateStudent : public Student
{
private:
    string major;

public:
    UndergraduateStudent(string n, long long int r, float totalFee, string m) : Student(n, r, totalFee), major(m) {}

    void displayData() override
    {
        Student::displayData();
        cout << "Major: " << major << endl;
    }
};

class Course
{
protected:
    string courseName;
    int courseCode;
    static int totalCourses;

public:
    Course(string cn, int cc) : courseName(cn), courseCode(cc) { totalCourses++; }

    string getCourseName() const { return courseName; }
    int getCourseCode() const { return courseCode; }
    static int getTotalCourses() { return totalCourses; }

    virtual void displayCourseDetails()
    {
        cout << "Course Name: " << courseName << "\nCourse Code: " << courseCode << endl;
    }

    ~Course() { totalCourses--; }
};

int Course::totalCourses = 0;

// Multilevel Inheritance: AdvancedCourse inherits from Course, GraduateCourse inherits from AdvancedCourse
class AdvancedCourse : public Course
{
protected:
    int difficultyLevel;

public:
    AdvancedCourse(string cn, int cc, int level) : Course(cn, cc), difficultyLevel(level) {}

    void displayCourseDetails() override
    {
        Course::displayCourseDetails();
        cout << "Difficulty Level: " << difficultyLevel << endl;
    }
};

class GraduateCourse : public AdvancedCourse
{
private:
    string researchArea;

public:
    GraduateCourse(string cn, int cc, int level, string area) : AdvancedCourse(cn, cc, level), researchArea(area) {}

    void displayCourseDetails() override
    {
        AdvancedCourse::displayCourseDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

int main()
{
    // Input and display for UndergraduateStudent
    string uName, uMajor;
    long long int uRollNumber;
    float uTotalFee;
    
    cout << "Enter details for an Undergraduate Student:\n";
    cout << "Name: ";
    cin >> uName;
    cout << "Roll Number: ";
    cin >> uRollNumber;
    cout << "Total Fee: ";
    cin >> uTotalFee;
    cout << "Major: ";
    cin >> uMajor;

    UndergraduateStudent uStudent(uName, uRollNumber, uTotalFee, uMajor);
    uStudent.displayData();

    // Input and display for GraduateCourse
    string gCourseName, gResearchArea;
    int gCourseCode, gDifficultyLevel;

    cout << "\nEnter details for a Graduate Course:\n";
    cout << "Course Name: ";
    cin >> gCourseName;
    cout << "Course Code: ";
    cin >> gCourseCode;
    cout << "Difficulty Level (1-5): ";
    cin >> gDifficultyLevel;
    cout << "Research Area: ";
    cin >> gResearchArea;

    GraduateCourse gCourse(gCourseName, gCourseCode, gDifficultyLevel, gResearchArea);
    gCourse.displayCourseDetails();

    cout << "\nTotal Students: " << Student::getTotalStudent() << endl;
    cout << "Total Courses: " << Course::getTotalCourses() << endl;

    return 0;
}
