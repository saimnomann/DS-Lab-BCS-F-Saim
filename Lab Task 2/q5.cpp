//Write a C++ program that dynamically creates a 2D matrix and provides:
//=> Addition of two matrices.
//=> Subtraction of two matrices.
//=> Ensure safe memory handling with proper allocation/deallocation.

#include<iostream>
using namespace std;
int** addition(int**m1,int**m2,int rows,int cols){
	int **m=new int*[rows];
	for(int i=0;i<rows;i++){
		m[i]=new int[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			m[i][j]=m1[i][j]+m2[i][j];
		}
	}
	return m;
	
}
int** subtraction(int**m1,int**m2,int rows,int cols){
	int **m=new int*[rows];
	for(int i=0;i<rows;i++){
		m[i]=new int[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			m[i][j]=m1[i][j]-m2[i][j];
		}
	}
	return m;
	
}
int main(){
	int **add,**sub,**m1,**m2,rows,cols;
	cout<<"Enter Number of Rows and Column: ";
	cin>>rows>>cols;
	m1=new int*[rows];
	m2=new int*[rows];
	for(int i=0;i<rows;i++){
		m1[i]=new int[cols];
		m2[i]=new int[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			m1[i][j]=0;
			m2[i][j]=0;
		}
	}
		for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		cout<<"Enter Element of Matrix 1 at "<<i+1<<" x "<<j+1<<": ";
		cin>>m1[i][j];
		}
	}
		for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		cout<<"Enter Element of Matrix 2 at "<<i+1<<" x "<<j+1<<": ";
		cin>>m2[i][j];
		}
	}
	add=addition(m1,m2,rows,cols);
	cout<<"Addition of Matrix"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		cout<<add[i][j]<<" ";
		}
		cout<<endl;
		}
		sub=subtraction(m1,m2,rows,cols);
		cout<<"Subtraction of Matrix"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		cout<<sub[i][j]<<" ";
		}
		cout<<endl;
}
for(int i=0;i<rows;i++){
	delete[]add[i];
	delete[]sub[i];
	delete[]m1[i];
	delete[]m2[i];
}
delete []m1;
delete []m2;
delete []add;
delete []sub;
}