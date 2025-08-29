//Design a program to handle marks of students in different courses using a jagged array
//(since each student is enrolled in a different number of courses).
//=> Input the number of courses each student takes.
//=> Dynamically allocate memory for each student accordingly.
//=> Calculate and display each student’s average mark

#include<iostream>
using namespace std;

int main(){
	int **marks;
	double total;
	int std_count;
	cout<<"Enter Number of Students: ";
	cin>>std_count;
	int course_count[std_count];
	marks=new int *[std_count];
	for(int i=0;i<std_count;i++){
		cout<<"Enter Number of Courses for Student "<<i+1<< ": ";
		cin>>course_count[i];
		marks[i]=new int[course_count[i]];
	}
	for(int i=0;i<std_count;i++){
		for(int j=0;j<course_count[i];j++){
			cout<<"Enter Student "<<i+1<<" Marks for Course "<<j+1<<": "<<endl;
			cin>>marks[i][j];
		}
	}
	for(int i=0;i<std_count;i++){
		for(int j=0;j<course_count[i];j++){
		total+=marks[i][j];
		}
	cout<<"Average Marks of Student "<<i+1<<" : "<<total/course_count[i]<<endl;
	total=0;
	}
	for(int i=0;i<std_count;i++){
		delete[]marks[i];
	}
	delete []marks;
}