#include<iostream>
using namespace std;
int main(){
int *arr,size;
	cout<<"Enter Size of Array : ";
	cin>>size;
	arr=new int [size];
	for(int i=0;i<size;i++){
		cout<<"Enter Element at "<<i<<" index: ";
		cin>>arr[i];
	}
	cout<<"Unsorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<size-1;i++){
		int min=i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
	}
			if(min!=i){
				int temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;
			}
	}
		cout<<"Sorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	delete []arr;
}