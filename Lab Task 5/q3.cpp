//Implement a C++ function sumTail(int n, int total) that calculates the sum
//of numbers from 1 to n using tail recursion. The recursive call should be the last
//operation in the function.
//2. Implement another function sumNonTail(int n) that calculates the same sum
//using non-tail recursion. This function should perform an operation (e.g., addition) after
//the recursive call returns. Compare the two implementations and explain the difference
//in their call stacks.
#include<iostream>
using namespace std;
int sumNonTail(int n){
	if(n==0){
		return 0;
	}
	else{
		return sumNonTail(n-1)+n;
	}
}
int sumTail(int n,int total){
	if(n<0){
	return total;
	}
	else{
		total+=n;
		return sumTail(n-1,total);
	}
}
int main(){
	int n,total=0;
	cout<<"Enter Number To Sum : ";
	cin>>n;
	int x=sumTail(n,total);
	cout<<"Sum Tail : "<<x;
	 x=sumNonTail(n);
	cout<<endl;
	cout<<"Sum Non Tail : "<<x;
}
//In Tail Recursion the call Stack from the top and the end of the function would be base case
//In Non Tail Recursion firstly we call the recursive call and in the end we perform operation