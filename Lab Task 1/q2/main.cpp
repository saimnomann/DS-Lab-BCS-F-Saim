//Create a C++ class named "Exam" using DMA designed to manage student exam records,
//complete with a shallow copy implementation? Define attributes such as student name, exam
//date, and score within the class, and include methods to set these attributes and display exam
//details. As part of this exercise, intentionally omit the implementation of the copy constructor
//and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
//shallow copy, and observe any resulting issues?
#include<iostream>
using namespace std;
class Exam{
	string *std_Name;
	string *exam_Date;
	double *score;
	public:
		Exam(){
		std_Name=new string("");
		exam_Date=new string("");
		score=new double(0.0);
		}
        void setStd_Name(string name){
        	*std_Name=name;
		}
		void setExam_Date(string date){
        	*exam_Date=date;
		}
		void setScore(double scr){
        	*score=scr;
		}
	    void ExamDetails(){
	    	cout<<"Student Name: "<<*std_Name<<endl;
	    	cout<<"Exam Date: "<<*exam_Date<<endl;
	    	cout<<"Score: "<<*score<<endl;
		}
		~Exam(){
			delete std_Name;
			delete exam_Date;
			delete score;
			cout<<"Destructor Called";
		}
		
};
int main(){
Exam e1;
cout<<"Student 1 Details:"<<endl;
e1.setStd_Name("Saim");
e1.setExam_Date("23-8-2025");
e1.setScore(75);
e1.ExamDetails();
Exam e2(e1);
cout<<"Student 2 Details:"<<endl;
e2.setStd_Name("Rafay");
e2.setScore(45);
e2.ExamDetails();
// Conclusion:
// By default, C++ uses a shallow copy, meaning that only pointer addresses
// are copied, not the data they point to. As a result, multiple objects
// share the same memory. Modifying one object changes the other.
// If a destructor is defined, this leads to a double deletion error
// because both objects attempt to free the same memory
}