//Create a program that solves the N-Queens problem for any given N using backtracking. The
//program should print all possible solutions for placing N queens on an N x N chessboard so
//that no two queens threaten each other. This task requires you to use a recursive function to
//place queens row by row , and a validation function to check if a queen can be placed in a
//specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
//row and try a different column.
#include<iostream>
using namespace std;
void solveQueens(int arr[20][20],int rows,int n){
	if(rows==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]==1){
					cout<<" Q ";
				}
				else{
				cout<<" . ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
		return;
}

for(int col=0;col<n;col++){
	bool isSafe=true;
	for(int j=0;j<rows;j++){
		if(arr[j][col]==1){
			isSafe=false;
			break;
		}
	}
	for(int i=rows-1,j=col-1;i>=0 && j>=0 ;i--,j--){
		if(arr[i][j]==1){
			isSafe=false;
			break;
		}
	}
	for(int i=rows-1,j=col+1;i>=0 &&j<n ;i--,j++){
		if(arr[i][j]==1){
			isSafe=false;
			break;
		}
	}
if(isSafe){
	arr[rows][col]=1;
	solveQueens(arr,rows+1,n);
	arr[rows][col]=0;
}
}
}
int main(){
	int n;
	cout<<"Enter N: ";
	cin>>n;
	int board[20][20]={0};
	solveQueens(board,0,n);
	
}