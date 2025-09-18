//6. Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
//upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
//decreases over time. After sorting, perform a complexity analysis: count and display the
//total number of swaps and comparisons performed during the sorting process.
#include<iostream>
using namespace std;
int main(){
	int *arr,size;
	cout<<"Enter Size of Sorted Array : ";
	cin>>size;
	arr=new int [size];
	for(int i=0;i<size;i++){
		cout<<"Enter Element At "<<i<<" Index: ";
		cin>>arr[i];
	}
	cout<<"Unsorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int gap=size,count=0,compCount=0;
	bool swapped=true;
	while(gap>1 ||swapped){
	gap=gap/1.3;
	if(gap<1){
		gap=1;
	}
	swapped=false;
	for(int i=0;i+gap<size;i++){
		compCount++;
		if(arr[i]>arr[i+gap]){
			int temp=arr[i];
			arr[i]=arr[i+gap];
			arr[i+gap]=temp;
			swapped=true;
			 count++;
		}
	}
	}
	cout<<"Sorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Total Number of Comparisions: "<<compCount<<endl; 
	cout<<"Total Number of Swaps: "<<count<<endl;
}