//Implement a program to represent a sparse matrix using a dynamic 2D array.
//=> Input matrix elements.
//=> Display the matrix in normal form.
//=> Display the matrix in compressed form (row, column, value).

#include<iostream>
using namespace std;
int main(){
	int **matrix,rows,cols;
	cout<<"Enter Number of Rows and Columns: ";
	cin>>rows>>cols;
	matrix=new int*[rows];
	for(int i=0;i<rows;i++){
		matrix[i]=new int[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<"Enter Element at "<<i<<"x"<<j<<": ";
			cin>>matrix[i][j];
		}
	}
	cout<<"Normal Matrix: "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Sparse Matrix: "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(matrix[i][j]!=0){
				cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
			}
		}
	}
	for(int i=0;i<rows;i++){
		delete[]matrix[i];
	}
	delete[]matrix;
}