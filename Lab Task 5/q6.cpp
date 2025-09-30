//Modify the provided "Rat in a Maze" code to handle a more complex version of the problem.
//The rat should now be able to move in four directions (up, down, left, and right) instead of just
//two. Your updated code should still use backtracking to find a valid path from the source (0,0) to
//the destination (N-1, N-1) while avoiding dead ends.
#include<iostream>
using namespace std;
int maze[4][4]={1,1,0,0,
0,1,0,1,
0,1,1,0,
0,0,1,1};
int Path[4][4]={0};
int solveMaze(int i,int j,int n){
	if(i==n-1 && j==n-1 && maze[i][j]==1){
		Path[i][j]=1;
		return 1;
	}
	else if(i<n && i>=0 && j<n &&j>=0 && maze[i][j]==1 && Path[i][j]==0){
	Path[i][j]=1;
			if(solveMaze(i,j+1,n)==1)return 1;
			if(solveMaze(i,j-1,n)==1)return 1;
			if(solveMaze(i+1,j,n)==1)return 1;
			if(solveMaze(i-1,j,n)==1)return 1;
			
		Path[i][j]=0;
		}
	
	return 0;
}
int main(){
	int res=solveMaze(0,0,4);
	if(res){
	cout<<"Path Found : "<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<Path[i][j]<<" ";
		}
		cout<<endl;
		
	}
	}
	else{
	cout<<"No Path Found ! "<<endl;
	}
}