#include<iostream>
using namespace std;
void heapifyUp(int heap[],int i,bool isMax){
	while(i>0){
		int parent=(i-1)/2;
		if(isMax){
		if(heap[i]>heap[parent]){
			int temp=heap[i];
			heap[i]=heap[parent];
			heap[parent]=temp;
			i=parent;
		}
		else{
			break;
		}
		}
		else{
			if(heap[i]<heap[parent]){	
			int temp=heap[i];
			heap[i]=heap[parent];
			heap[parent]=temp;
			i=parent;
		}
		else{
			break;
		}
		}
	}
}
void insertHeap(int heap[],int &size,int val,bool isMax){
	if(size<100){
	heap[size]=val;
	heapifyUp(heap,size,isMax);
	size++;
	}
	else{
	cout<<"Heap Overflow"<<endl;
	return;
	}
}

void printHeap(int heap[],int size){
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	}
}
void heapifyDown(int heap[],int size,int i,bool isMax){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(isMax){
		if(left<size && heap[left]>heap[largest]){
			largest=left;
		}
		if(right<size &&heap[right]>heap[largest]){
			largest=right;
		}
		if(i!=largest){
			int temp=heap[i];
			heap[i]=heap[largest];
			heap[largest]=temp;
			heapifyDown(heap,size,largest,isMax);
		}
	}
	else{
		if(left<size && heap[left]<heap[largest]){
			largest=left;
		}
		if(right<size && heap[right]<heap[largest]){
			largest=right;
		}
		if(i!=largest){
			int temp=heap[i];
			heap[i]=heap[largest];
			heap[largest]=temp;
			heapifyDown(heap,size,largest,isMax);
		}
	}
	
}
void deleteHeap(int heap[],int &size,bool isMax){
	if(size==0)return;
	heap[0]=heap[size-1];
	size--;
	heapifyDown(heap,size,0,isMax);
}
void update_key(int heap[],int i,int size,int new_val,bool isMax){
	int old_val=heap[i];
	heap[i]=new_val;
	if(isMax){
		if(new_val>old_val){
			heapifyUp(heap,i,isMax);
		}
		else{
			heapifyDown(heap,size,i,isMax);
		}
	}
	else{
		if(new_val<old_val){
			heapifyUp(heap,i,isMax);
		}
		else{
		heapifyDown(heap,size,i,isMax);
		}
	}
}
int main() {
    int maxheap[100],minHeap[100];
    int maxsize = 0,minSize=0;
    insertHeap(maxheap,maxsize,8,true);
    insertHeap(maxheap,maxsize,7,true);
    insertHeap(maxheap,maxsize,6,true);
    insertHeap(maxheap,maxsize,5,true);
    insertHeap(maxheap,maxsize,4,true);
    
    cout<<"Max Heap : "<<endl;
    printHeap(maxheap,maxsize);
	cout<<endl;
    insertHeap(minHeap,minSize,8,false);
    insertHeap(minHeap,minSize,7,false);
    insertHeap(minHeap,minSize,6,false);
    insertHeap(minHeap,minSize,5,false);
    insertHeap(minHeap,minSize,4,false);
    
    cout<<"Min Heap : "<<endl;
    printHeap(minHeap,minSize);
    cout<<endl;
    
    cout<<"Updating Root : "<<endl;
    update_key(maxheap,0,maxsize,1,true);
    printHeap(maxheap,maxsize);
    
    cout<<endl;
    cout<<"Updating 2 value : "<<endl;
    update_key(minHeap,2,minSize,10,false);
    printHeap(minHeap,minSize);
    
    cout<<endl;
    cout<<"Deleting Root : "<<endl;
    deleteHeap(minHeap,minSize,false);
    printHeap(minHeap,minSize);
    
    


}