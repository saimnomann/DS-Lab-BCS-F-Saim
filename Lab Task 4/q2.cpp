
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
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"Sorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	delete []arr;
}