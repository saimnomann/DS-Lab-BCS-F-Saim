//Write a C++ program that implements the Ackermann function, which is a classic example of
//nested recursion. The function ackermann(int m, int n) is defined as:
//? If m=0, return n+1.
//? If m>0 and n=0, return ackermann(m-1, 1).
//? If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
//This task requires you to trace the execution and understand how one recursive call is a
//parameter to another.
#include<iostream>
using namespace std;
int AckermannFunction(int m,int n){
	if(m==0){
		cout<<"Returning N+1 : "<<n+1<<endl;
		return n+1;
	}
	if(m>0 && n==0){
		cout<<"Returning Function m-1 and 1 : "<<AckermannFunction(m-1,1)<<endl;
		return AckermannFunction(m-1,1);
	}
	if(m>0 && n>0){
		cout<<"Returning Function m-1 and m,n-1 : "<<AckermannFunction(m-1,AckermannFunction(m,n-1))<<endl;
		return AckermannFunction(m-1,AckermannFunction(m,n-1));
	}
}
int main(){
	cout<<"Enter M and N : ";
	int m,n;
	cin>>m>>n;
	int res=AckermannFunction(m,n);
	cout<<"Result : "<<res;
}