#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    long long int rollNumber;
public:
   Student( string n , long long int r) : name(n) , rollNumber(r) {}

   void displayData(){
    cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
   }

   void updateDetails( string n , long long int r) {
    name = n ;
    rollNumber = r ;

   }
};

class Course {
private:
   string courseName;
   int courseCode ;
public : 
  Course( string cn , int cc) : courseName(cn) , courseCode(cc) {}

  void displayCourseDetails() {
    cout << "Course Name: " << courseName << "\nCourse Code: " << courseCode << endl ;
  }

  void updateCourseDetails ( string cn , int cc) {
    courseName = cn ;
    courseCode = cc ;
  }

};

int main(){
    Student student1 ("Sujal" , 2311981614);
    student1.displayData();

    Course course1("Mathematics", 301);
    course1.displayCourseDetails();

    
    student1.updateDetails("Diwanshu", 2311981618);
    student1.displayData();

    course1.updateCourseDetails("Physics", 302);
    course1.displayCourseDetails();

    return 0;
}