//Task #1:
//Implement a program that dynamically allocates a 1D array of integers.
//=> The size should be given by the user.
//=> Initialize all elements with zero.
//=> Then, let the user update values at different positions.
//=> Finally, print the array and deallocate memory properly
#include<iostream>
using namespace std;
int main(){
	int *arr,size;
	cout<<"Enter the size of array: ";
	cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++){
		arr[i]=0;
	}
	for(int i=0;i<size;i++){
		cout<<"Enter Element: ";
		cin>>arr[i];
	}
	for(int i=0;i<size;i++){
		cout<<"Element at "<<i+1<<" place: "<<arr[i]<<endl;
	}
	delete []arr;
}