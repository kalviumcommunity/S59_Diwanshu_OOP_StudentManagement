#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Fee {
private:
  float totalFee ;
  float feePaid ;
public :
  Fee (float totalFee) : totalFee(totalFee) , feePaid(0) {}
  
   void makePayment(float amount){
     if(amount > 0 && feePaid + amount <= totalFee) {
        feePaid += amount ;
         cout << "Payment of " << amount << " made Successfully . " <<endl ;
     } else {
         cout << "Invalid payment amount. Please check the balance." << endl;
     }

   }

   void displayFeeDetails()
   {
       cout << "Total Fee: " << totalFee << "\nFee Paid: " << feePaid << "\nRemaining Balance: " << totalFee - feePaid << endl;
   }
};
class Student {
private:
    string name;
    long long int rollNumber;
    Fee fee;
public:
   Student( string n , long long int r , float totalFee) : name(n) , rollNumber(r) , fee(totalFee) {}

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
           cout << "Name: " << name << "\nRoll Number: " << this->rollNumber << endl;
           fee.displayFeeDetails();
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
    Student student1("Sujal", 2311981614, 5000.0);
    student1.displayData();

    student1.makeFeePayment(1500.0);
    student1.displayData();

    Course course1("Mathematics", 301);
    course1.displayCourseDetails();

    student1.updateDetails("Diwanshu", 2311981618);
    student1.displayData();


    course1.updateCourseDetails("Physics", 302);
    course1.displayCourseDetails();

    return 0;
}