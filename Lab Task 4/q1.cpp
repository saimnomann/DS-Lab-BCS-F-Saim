#include<iostream>
using namespace std;
int linearSearch(int *arr,int size,int target){
	for(int i=0;i<size;i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}
int main(){
int *arr,target,size;
cout<<"Enter Size of Array"<<endl;
cin>>size;
arr=new int [size];
for(int i=0;i<size;i++){
	cout<<"Enter Element at "<<i<<" index: "<<endl;
	cin>>arr[i];
}
cout<<"Enter Target Element"<<endl;
cin>>target;
	int i=linearSearch(arr,size,target);
	if(i==-1){
		cout<<"Target Not Found"<<endl;
	}
	else{
		cout<<"Target Found at "<<i<<" index"<<endl;
	}
	delete []arr;
}