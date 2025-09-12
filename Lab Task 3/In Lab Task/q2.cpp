#include<iostream>
using namespace std;
int main(){
	int arr[10]={5,1,3,6,2,9,7,4,8,10};
	for(int i=0;i<10;i++){
		for(int j=0;j<10-1;j++){
			if(arr[j]<arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
	cout<<"Sorted Array: "<<endl;
	for(int i=0;i<10;i++){
		cout<<"Element "<<i+1<<":"<<arr[i]<<endl;
	}
}