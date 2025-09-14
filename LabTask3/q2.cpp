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
Node* mergeList(Node *l1,Node *l2){
	if(l1==NULL){
		return l2;
	}
	if(l2==NULL){
		return l1;
	}
	Node *head;
	Node *current;
		if(l1->data<l2->data){
		head=l1;
		current=l1;
		l1=l1->next;
		}
		else{
			head=l2;
			current=l2;
			l2=l2->next;
		}
while(l1!=NULL && l2!=NULL){
	if(l1->data<l2->data){
		current->next=l1;
		l1=l1->next;
	}
	else{
		current->next=l2;
		l2=l2->next;
	}
	current=current->next;

}
if(l1!=NULL){
	current->next=l1;
}
if(l2!=NULL){
	current->next=l2;
}
return head;
}
int main(){
	LinkedList list1;
	LinkedList list2;
	list1.insertAtEnd(1);
	list1.insertAtEnd(3);
	list1.insertAtEnd(5);
	list2.insertAtEnd(2);
	list2.insertAtEnd(4);
	list2.insertAtEnd(6);
	list1.head=mergeList(list1.head,list2.head);
	list2.head=NULL;
	list1.display();
}