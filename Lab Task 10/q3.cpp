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
int kValue(int heap[],int size,int k){
	for(int i=size/2-1;i>=0;i--){
		heapify(heap,size,i);
	}
	int result=-1;
	for(int i=size-1;i>=size-k;i--){
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		result=heap[i];
		heapify(heap,i,0);
	}
	return result;
}
int main(){
	
	int heap[]={1,23,1, 23, 12, 9, 30, 2, 50};
	int k=3;
	int size=sizeof(heap)/sizeof(heap[0]);
	cout<<kValue(heap,size,k);
	int heap2[]={12,3,5,7,19};
	k=2;
	cout<<endl;
	size=sizeof(heap2)/sizeof(heap2[0]);
	cout<<kValue(heap2,size,k);
	
}