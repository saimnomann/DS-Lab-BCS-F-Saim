//Create a dynamic program to store temperature readings of a city for n days and m different times in a day
//using a 2D array.
//=> Calculate the daily average temperature.
//=> Find the hottest and coldest day.
#include<iostream>
using namespace std;
int main(){
	int n,m,**temp;
	cout<<"Enter Number of Days and Different Times: ";
	cin>>n>>m;
	temp=new int*[n];
	for(int i=0;i<n;i++){
	temp[i]=new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"Enter Temperature for Day "<<i+1<<": ";
			cin>>temp[i][j];
		}
	}
	double *avg=new double[n];
	int hot=0,cold=0;
	for(int i=0;i<n;i++){
		double sum=0;
		for(int j=0;j<m;j++){
			sum+=temp[i][j];
		}
		avg[i]=sum/m;
		if(avg[i]>avg[hot]){
			hot=i;
		}
		if(avg[i]<avg[cold]){
			cold=i;
		}
	}
	cout<<"Daily Average Temperature: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Day "<<i+1<<" Temperature: "<<avg[i]<<"C"<<endl;
	}
	cout<<"Hottest Day is Day "<<hot+1<<endl;
	cout<<"Coldest Day is Day "<<cold+1<<endl;
	for(int i=0;i<m;i++){
		delete[]temp[i];
	}
	delete[]temp;delete[]avg;
}