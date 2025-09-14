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
	cout<<"Deleting Node with "<<data<<endl;
}	
};
class LinkedList{
		Node *head;
	public:
		Node *getHead(){
			return head;
		}
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
	void update(int prev,int val){
		if(head==NULL){
			cout<<"Linked List is Empty"<<endl;
		}
		else{
			Node *temp=head;
			bool found=false;
		while(temp!=NULL){
			if(temp->data==prev){
				temp->data=val;
				cout<<"Value Updated"<<endl;
				found=true;
				break;
			}
			else{
				temp=temp->next;
			}
			
		}
		if(!found)
		cout<<"Item Not Found"<<endl;
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
Node* reverse(Node *head){
	Node *curr=head;
	Node *prev=NULL;
	Node *next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
return prev;
	
}
bool palindrome(LinkedList &list){
	if(list.getHead()==NULL || list.getHead()->next==NULL){
		return true;
	}
	Node *slow=list.getHead();
	Node *fast=list.getHead();
	while(fast->next!=NULL &&fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	Node *newHead=reverse(slow->next);
	Node *first=list.getHead();
	Node *second=newHead;
	while(second!=NULL){
		if(first->data!=second->data){
		return false;
		}
		else{
			first=first->next;
			second=second->next;
		}
	}
	slow->next=reverse(newHead);
	return true;
}

    int main(){
    	LinkedList list1;
	list1.insertAtEnd(10);
	list1.insertAtEnd(20);
	list1.insertAtEnd(10);
	bool flag=palindrome(list1);
	if(flag){
		cout<<"It is a Palindrome"<<endl;
	}
	else{
		cout<<"It is not A Palindrome"<<endl;
	}
	list1.display();
	list1.update(10,20);
    flag=palindrome(list1);
	if(flag){
		cout<<"It is a Palindrome"<<endl;
	}
	else{
		cout<<"It is not A Palindrome"<<endl;
	}
	list1.display();
}
