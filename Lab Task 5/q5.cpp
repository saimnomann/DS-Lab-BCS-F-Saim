//Implement a Sudoku solver using the backtracking technique. The program should take a
//partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
//Your algorithm should:
//1. Find an empty cell.
//2. Try placing a number from 1 to 9 in the empty cell.
//3. Check if the number is valid in the current row, column, and 3x3 subgrid.
//4. If valid, recursively call the function to solve the rest of the puzzle.
//5. If the recursive call doesn't lead to a solution,
//backtrack by resetting the cell to 0 and trying the next number.

#include<iostream>
using namespace std;
int sudoko[9][9]={0};
bool isValid(int grid[9][9],int row,int col,int num){
	bool valid=true;
		for(int j=0;j<9;j++){
			if(grid[row][j]==num){
				return false;
			}
		}
		for(int i=0;i<9;i++){
			if(grid[i][col]==num){
				return false;
			}
		}
	int startRow=row-(row%3);
	int startCol=col-(col%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[startRow+i][startCol+j]==num){
				return false;
			}
		}
	}
	return true;
}
bool solveSudoko(int grid[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(grid[i][j]==0){
			for(int num=1;num<=9;num++){
				if(isValid(grid,i,j,num)){
				grid[i][j]=num;
				if(solveSudoko(grid))return true;
				grid[i][j]=0;
			
			}
					
			}
			return false;
		}
	}
}
return true;
}
void printGrid(int grid[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	    int grid[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},
    
    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
    };
    if(solveSudoko(grid)){
    	cout<<"Solution Exists : "<<endl;
    	printGrid(grid);
	}
	else{
		cout<<"Solution Does Not Exist ";
	}
}