//Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
//=> Rows represent benches, columns represent seats on each bench.
//=> Initialize the array with 0 (empty).
//=> Let the user fill seats (1 for occupied).
//=> Print the final seating chart in matrix form

#include<iostream>
using namespace std;
int main(){
	char flag;
	int **classroom,rows,cols;
	cout<<"Enter Number of Benches: ";
	cin>>rows;
	cout<<"Enter Number of Seats: ";
	cin>>cols;
classroom=new int*[rows];
	for(int i=0;i<rows;i++){
		classroom[i]=new int [cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			classroom[i][j]=0;
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<"Is this Seat Ocuppied:(Y for Yes and N for No) ";
			cin>>flag;
			if(flag=='Y'){
				classroom[i][j]=1;
			}
			else{
			classroom[i][j]=0;		
			}
		
		}
	}

	for(int i=0;i<rows;i++){
	for(int j=0;j<cols;j++){
	cout<<classroom[i][j]<<" ";
		}
	cout<<endl;
	}
	for(int i=0;i<rows;i++){
		delete[]classroom[i];
	}
	delete[]classroom;
}