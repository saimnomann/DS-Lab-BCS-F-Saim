#include<iostream>
using namespace std;
int binarySearch(int *arr,int l,int h,int target){
	if(l<=h){
		int mid=(h+l)/2;
		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]>target){
			return binarySearch(arr,l,mid-1,target);
		}
		else{
			return binarySearch(arr,mid+1,l,target);
		}
	}
	return -1;
}
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
	for(int i=1;i<size;i++){
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
			cout<<"Sorted Array : "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter Target Element : "<<endl;
	int target;
	cin>>target;
	int i=binarySearch(arr,0,size,target);
	if(i==-1){
		cout<<"Target Not Found!"<<endl;
	}
	else{
		cout<<"Target Found At Index "<<i<<endl;
	}
	delete []arr;
}
