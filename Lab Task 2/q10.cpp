//Design a program that maintains library book records using dynamic arrays.
//=> Each row represents a category (e.g., Fiction, Science, History).
//=> Each category has a different number of books (use a jagged array).
//=> Store book IDs dynamically and allow the user to search for a given book ID.
//=> Print whether the book is available and in which category
#include<iostream>
using namespace std;
int main(){
string **library;
string *category;
int count;
cout<<"Enter Number of Categories: ";
cin>>count;
library=new string* [count];
category=new string[count];
int *book_count=new int[count];

for(int i=0;i<count;i++){
	cout<<"Enter Name of Category "<<i+1<<": ";
	cin>>category[i];
	cout<<"Enter Number of Books for "<<category[i]<<": ";
	cin>>book_count[i];
	library[i]=new string[book_count[i]];
}
for(int i=0;i<count;i++){
	for(int j=0;j<book_count[i];j++){
		cout<<"Enter Book Id for "<<category[i]<<": ";
		cin>>library[i][j];
	}
}
string id;
cout<<"Enter Book Id to Search: ";
cin>>id;
bool found=false;
for(int i=0;i<count && !found;i++){
	for(int j=0;j<book_count[i];j++){
		if(library[i][j]==id){
			cout<<"Book Id Found in Category: "<<category[i]<<endl;
			found=true;
			break;
		}
	}
}
if(!found){
	cout<<"Book Id Not Found"<<endl;
}
for(int i=0;i<count;i++){
	delete[]library[i];
}
delete[] library;
delete[] book_count;
delete[] category;
}


