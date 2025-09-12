#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter Number of Employee Id: ";
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++){
		cout<<"Enter Employee Id: ";
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	int low=0,high=n-1,target;
	bool found;
	cout<<"Enter Target: ";
	cin>>target;
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[mid]==target){
			cout<<"Element Found At Postion "<<mid+1<<endl;
			found=true;
			break;
		}
		else if(arr[mid]<target){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(found==false){
		arr[n]=target;
			for(int i=0;i<n+1;i++){
		for(int j=0;j<n;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<n+1;i++){
		cout<<"Employee Id "<<i+1<<" : "<<arr[i];
		cout<<endl;
		
	}
	}
	
}