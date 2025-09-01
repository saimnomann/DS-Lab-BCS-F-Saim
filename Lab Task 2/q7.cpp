//A company has multiple departments, each department has a different number of employees.
//=> Use a jagged array where each row corresponds to a department and columns store employee
//salaries.
//Calculate:
//-> The highest salary in each department.
//-> The department with the overall maximum average salary.
#include<iostream>
using namespace std;
int main(){
	int **company,dept;
	cout<<"Enter Number of Department: ";
	cin>>dept;
	int emp[dept];
	int temp[dept];
	company=new int*[dept];
	for(int i=0;i<dept;i++){
		cout<<"Enter Number of Employees in "<<i+1<<" Department: ";
		cin>>emp[i];
}
for(int i=0;i<dept;i++){
	company[i]=new int[emp[i]];
}
for(int i=0;i<dept;i++){
	for(int j=0;j<emp[i];j++){
		cout<<"Enter Salary of Employee "<<j+1<<" of Department "<<i+1<<": ";
		cin>>company[i][j];
	}
}
	double maxAvg=0;
	int bestDept=0;
for(int i=0;i<dept;i++){
		int highest=company[i][0];
		int sum=0;
	for(int j=0;j<emp[i];j++){
			sum+=company[i][j];
		if(company[i][j]>highest){
			highest=company[i][j];
		}
	}
	cout<<"The Highest Salary in Department "<<i+1<<" is "<<highest<<endl;
	double avg=sum/emp[i];
	if(avg>maxAvg){
		maxAvg=avg;
		bestDept=i;
	}	
}
cout<<"The Best Department is Department "<<bestDept+1<<" With Highest Average is "<<maxAvg;
for(int i=0;i<dept;i++){
	delete[]company[i];
}
delete[]company;
	
}