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
		cout<<"Deleting Node With Value: "<<data<<endl;
	}
	
};
class LinkedList{
	public:
	Node *head;
	LinkedList(){
		head=NULL;
	}
	void insertAtEnd(int val){
		Node *newNode=new Node(val);
		if(head==NULL){
			head=newNode;
		}
		else{
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
		}
	}
	void display(){
		if(head==NULL){
			cout<<"Linked List is Empty"<<endl;
		}
		else{
		Node *temp=head;
		cout<<"Linked List: "<<endl;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
		}
	}
	~LinkedList(){
		Node *current=head;
		while(current!=NULL){
			Node *n=current->next;
			delete current;
			current=n;
		}
		 cout << "LinkedList destroyed successfully.\n";
	}
};
Node* ReverseInGroup(Node *head,int k){
	if(head==NULL||k<=0){
		return head;
	}
	Node *curr=head;
	Node *newHead=NULL;
	Node *prevTail=NULL;

	while(curr!=NULL){
	Node *check=curr;
	int nodeCount=0;
	while(check!=NULL &&nodeCount<k){
		check=check->next;
		nodeCount++;
	}
	if(nodeCount<k){
		if(prevTail!=NULL)prevTail->next=curr;
		break;
	}
		Node *groupHead=curr;
	    Node *prev=NULL;
	    Node *next=NULL;
	    int count=0;
	    
	while(curr!=NULL && count<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
		
	}
	if(newHead==NULL){
		newHead=prev;
	}
	if(prevTail!=NULL){
		prevTail->next=prev;
	}
	prevTail=groupHead;
	}
	return newHead;
}
int main(){
	LinkedList list;
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);
	list.insertAtEnd(6);
	list.insertAtEnd(7);
	list.insertAtEnd(8);
	list.head=ReverseInGroup(list.head,3);
	list.display();
}