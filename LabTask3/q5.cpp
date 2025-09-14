#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node *prev;
	Node(int val){
		data=val;
		next=NULL;
		prev=NULL;
	}
	~Node(){
		cout<<"Deleting Node with Data "<<data<<endl;
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
	void insertAtStart(int val){
		Node *newNode=new Node(val);
			newNode->next=head;
			head=newNode;
	
	}
};
Node* convertToDoubly(Node *head){
	Node *prev=NULL;
	Node *curr=head;
	while(curr!=NULL){
		curr->prev=prev;
		prev=curr;
		curr=curr->next;
	}
	return head;
}
Node*convertToCircular(Node *head){
	Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	return head;
}
int main(){
	LinkedList list1,list2;
	for(int i=0;i<5;i++){
		list1.insertAtEnd(i+1);
	}
		for(int i=0;i<5;i++){
		list2.insertAtEnd(i+1);
	}
	Node *d=convertToDoubly(list1.head);
	cout<<"Doubly: "<<endl;
	Node *temp=d;
   while (temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL) {
            cout << " <-> ";
        }
        temp=temp->next;
    }
    cout << endl;
    cout<<"Circular: "<<endl;
    Node *c=convertToCircular(list2.head);
    temp=c;
    for(int i=0;i<6;i++){
    	cout<<temp->data;
    	if(i<5){
    		cout<<"->";
		}
		temp=temp->next;
	}
}