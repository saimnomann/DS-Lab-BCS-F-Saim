#include<iostream>
using namespace std;
struct Participant{
	string name;
	int finishTime;
};
void merge(Participant p[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	Participant L[n1],R[n2];
	for(int i=0;i<n1;i++){
		L[i]=p[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=p[mid+i+1];
	}
	int i=0,j=0,k=left;
	while(i<n1 && j<n2){
		if(L[i].finishTime<=R[j].finishTime){
			p[k]=L[i];
			i++;
			k++;
		}
		else{
			p[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		p[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		p[k]=R[j];
		j++;
		k++;
	}
}
void mergeSort(Participant p[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(p,left,mid);
		mergeSort(p,mid+1,right);
		merge(p,left,mid,right);
	}
}
int main(){
	Participant p[10];
	for(int i=0;i<10;i++){
		cout<<"Enter name and finish time for runner "<<i+1<<" Name : ";
		cin>>p[i].name>>p[i].finishTime;
	}
	mergeSort(p,0,9);
	cout<<"Top 5 fastest runners : "<<endl;
	for(int i=0;i<5;i++){
		cout<<i+1<<"."<<" "<<p[i].name<<" - "<<p[i].finishTime<<" seconds"<<endl;
	}
	
}