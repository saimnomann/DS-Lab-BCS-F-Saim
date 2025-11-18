#include<iostream>
using namespace std;
void heapify(int heap[],int size,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && heap[left]>heap[largest]){
		largest=left;
	}
	if(right<size && heap[right]>heap[largest]){
		largest=right;
	}
	if(largest!=i){
		int temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;
		heapify(heap,size,largest);
	}
}
void convertintoMax(int heap[],int size){
	for(int i=size/2-1;i>=0;i--){
		heapify(heap,size,i);
	}
	for(int i=size-1;i>size;i--){
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
	int arr[]={3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int size=sizeof(arr)/sizeof(arr[0]);
	convertintoMax(arr,size);
	printHeap(arr,size);
}