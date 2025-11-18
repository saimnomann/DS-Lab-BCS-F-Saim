#include<iostream>
using namespace std;

bool checkHeap(int heap[],int size){
	for(int i=0;i<=(size-2)/2;i++){
		int left=2*i+1;
		int right=2*i+2;
		if(left<size && heap[i]<heap[left])return false;
		if(right<size && heap[i]<heap[right])return false;
		
	}
	return true;
}
void heapify(int heap[],int size,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && heap[left]>heap[largest] ){
		largest=left;
		
	}
	if(right<size &&heap[right]>heap[largest]){
		largest=right;
	}
	if(largest!=i){
		int temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;
		heapify(heap,size,largest);
	}
}
void heapSort(int heap[],int size){
	for(int i=(size/2)-1;i>=0;i--){
		heapify(heap,size,i);
	}
	for(int i=size-1;i>0;i--){
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		heapify(heap,i,0);
	}
}
void printHeap(int heap[],int size){
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	}
}
int main(){
	int heap[]={8,7,6,5,4};
	int size=sizeof(heap)/sizeof(heap[0]);
	bool temp=checkHeap(heap,size);
	if(temp){
		cout<<"It is a Max Heap"<<endl;
	}
	else{
		cout<<"It is not a Max Heap"<<endl;
	}
	cout<<"Sorted Heap : "<<endl;
	heapSort(heap,size);
	printHeap(heap,size);
	
}