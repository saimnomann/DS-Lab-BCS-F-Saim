#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int val){
	data=val;
	next=NULL;
}	
~Node(){
	cout<<"Deleting Node with data "<<data<<endl;
}
};
class CircularLinkedList{
	public:
		Node *head;
		Node *tail;
	CircularLinkedList(){
		head=NULL;
		tail=NULL;
	}
	~CircularLinkedList(){
		Node *curr=head;
		do{
		Node *next=curr->next;
		
		delete curr;
		curr=next;
		}while(curr!=head);
	}
	void insertAtEnd(int val){
		Node *newNode=new Node(val);
		if(head==NULL){
			head=newNode;
			tail=newNode;
			tail->next=head;
		}
		else{
			
	     	tail->next=newNode;
	     	tail=newNode;
	     	tail->next=head;
		}
	}
void display(){
		if(head==NULL){
			cout<<"Linked List is Empty"<<endl;
		}
		else{
			Node *temp=head;
			cout<<"Linked List: "<<endl;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
		}
	}
};
	

Node* JosephusProblem(int n,int k){
	CircularLinkedList list;
	for(int i=0;i<n;i++){
		list.insertAtEnd(i+1);
	}
	list.display();
	Node *curr=list.head;
	Node *prev=list.tail;
	while(curr!=curr->next){
		for(int i=0;i<k;i++){
			prev=curr;
			curr=curr->next;
			
		}
		prev->next=curr->next;
		if(curr==list.head){
			list.head=curr->next;
			}
			delete curr;
			curr=prev->next;
		}
	return curr;
	}


int main(){
	Node *temp=JosephusProblem(7,3);
	cout<<"Survivor: "<<temp->data<<endl;
}