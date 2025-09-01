//Create a dynamic program that manages monthly expenses for a family.
//=> Use a 1D dynamic array to store expenses for n months.
//=> Add a feature to resize the array if the user wants to track more months later.
//=> Compute and display the total and average expenses.
#include<iostream>
using namespace std;
int* resize(int *arr,int size,int new_size){
	if(size==new_size){
		return arr;
}
	int *new_arr=new int[new_size];
	int limit =(size<new_size)?size:new_size;
    for (int i=0;i<limit;i++) {
        new_arr[i]=arr[i];
    }
    for(int i=size;i<new_size;i++){
    	cout<<"Enter Expense for Month "<<i+1<<": ";
    	cin>>new_arr[i];
	}
	delete [] arr;
	return new_arr;
}
int main(){
int *expense,n,size,total=0;
cout<<"Enter Number of Months: ";
cin>>n;
expense=new int [n];
for(int i=0;i<n;i++){
	cout<<"Enter Expense for Month "<<i+1<<": ";
	cin>>expense[i];
}
cout<<"To resize Expense Enter number of months: ";
cin>>size;
expense=resize(expense,n,size);

for (int i=0;i<size;i++){
	total+=expense[i];
}
cout<<"The Total Expense is "<<total<<" and Average is "<<total/size<<endl;
delete[]expense;
}