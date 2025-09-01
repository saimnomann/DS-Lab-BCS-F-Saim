//Implement a Safe Pointer class to wrap around an integer pointer.
//=> Provide methods for setValue(), getValue(), and release().
//=>
//Demonstrate the class by storing marks of 5 students and printing them safely without
//direct pointer manipulation.
#include<iostream>
using namespace std;
class SafePointer{
	int *ptr;
	public:
		SafePointer(int size){
			ptr=new int [size];
		}
		void setValue(int index,int value){
			ptr[index]=value;
		}
		int getValue(int index){
			return ptr[index];
		}
		void release(){
			delete[]ptr;
			ptr=nullptr;
		}
		~SafePointer(){
			delete[]ptr;
		}	
};
int main(){
	SafePointer ptr(5);
	int val;
	for(int i=0;i<5;i++){
		cout<<"Enter Student "<<i+1<<" Marks: ";
		cin>>val;
		ptr.setValue(i,val);
	}
		for(int i=0;i<5;i++){
	    cout<<ptr.getValue(i)<<" ";
	}
	ptr.release();
}