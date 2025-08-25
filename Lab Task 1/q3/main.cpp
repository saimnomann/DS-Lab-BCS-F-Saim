//Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
//Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
//Demonstrate the behavior of both shallow and deep copy using test cases.
#include<iostream>
using namespace std;
class Box{
	int *size;
    public:
		Box(int s){
			size=new int(s);
		}
		Box(const Box& b){
			size=new int (*b.size);
		}
		Box& operator=(const Box &b){
			if (this!=&b){
				delete size;
				this->size=new int(*b.size);
			}
				return *this;
			
		}
		void getSize(){
			cout<<*size<<endl;
		}
		~Box(){
			delete size;
		}
};
int main(){
	Box b1(10);
	Box b2(b1);
	Box b3(20);
	b3=b1;
	cout<<"Box 1 size: ";
	b1.getSize();
	cout<<"Box 2 size: ";
	b2.getSize();
	cout<<"Box 3 size: ";
	b3.getSize();
	
}
 We see in the above example that if I make a copy constructor with deep copy, it assigns different memory to the variable.
 But if I comment out the custom copy constructor, the default copy constructor is called,
 and it performs shallow copying, meaning it copies the variable to the same address.
 As a result, if I change the value of the variable in one object, the value in the other object also changes.