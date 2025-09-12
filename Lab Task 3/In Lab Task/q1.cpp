#include<iostream>
using namespace std;
int main(){
int size,target;
bool found=false;
cout<<"Enter The Size of Array: ";
cin>>size;
int *arr;
arr=new int [size];
for(int i=0;i<size;i++){
	cout<<"Enter Element "<<i+1<<" : ";
	cin>>arr[i];
}
cout<<"Enter Target Element: ";
cin>>target;
for(int i=0;i<size;i++){
	if(arr[i]==target){
		cout<<"Target Found at "<<i<<" Place"<<endl;
		found=true;
		break;
	}
}
if(found==false){
	cout<<"Target Not Found!"<<endl;
}
delete[]arr;
}