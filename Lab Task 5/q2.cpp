//Write a simple C++ program that demonstrates direct recursion. Create a function
//printNumbers(int n) that prints numbers from n down to 1 by calling itself
//directly.
//2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
//and functionB(int n). functionA should call functionB, and functionB
//should call functionA, forming a cycle that prints numbers in a specific pattern.
//Ensure both programs have a base condition to prevent infinite loops.

#include<iostream>
using namespace std;
int printNumbers(int n){
	if(n==0){
		return 0;
	}
	else{
		cout<<n<<" ";
		return printNumbers(n-1);
	}
}
int functionA(int n){
	if(n==0){
		return 0;
	}
	else {
		cout<<n<<" ";
		return functionA(n-1);
	}
}
int functionB(int n){
	if(n==0){
		return 0;
	}
	else{
		cout<<n<<" ";
		return functionB(n-1);
	}
}
int main(){
	int n;
	cout<<"Enter Numbers You want to Print : ";
	cin>>n;
	cout<<"Direct Recursion : "<<endl;
	printNumbers(n);
	cout<<endl;
	cout<<"Indirect Recursion : "<<endl;
	printNumbers(n);
}