#include<iostream>
using namespace std;
int interpolationSearch(int *arr,int size,int target){
	int low=0,high=size-1;
	while(low<=high && target>=arr[low] && target<=arr[high]){
		int mid=low+((high-low)/arr[high]-arr[low])*(target-arr[low]);
		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]<target){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}
int main(){
	int *arr,size;
	cout<<"Enter Size of Sorted Array : ";
	cin>>size;
	arr=new int [size];
	for(int i=0;i<size;i++){
		cout<<"Enter Element of Sorted Array At "<<i<<" Index: ";
		cin>>arr[i];
	}
	cout<<"Enter Target Element : "<<endl;
	int target;
	cin>>target;
	int i=interpolationSearch(arr,size,target);
		if(i==-1){
		cout<<"Target Not Found!"<<endl;
	}
	else{
		cout<<"Target Found At Index "<<i<<endl;
	}
	delete []arr;
	
}