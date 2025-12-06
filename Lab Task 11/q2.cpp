#include<iostream>
using namespace std;
struct Node{
	string key;
	string value;
	Node *next;
	Node(string k,string v){
		key=k;
		value=v;
		next=nullptr;
	}
};
class DictionaryApp{
	Node **table;
	int count;
	public:
	DictionaryApp(){
		table=new Node*[100];
		for(int i=0;i<100;i++){
			table[i]=nullptr;
		}
		count=0;
	}
	int hashFunction(string key){
		int sum=0;
		for(int i=0;key[i]!='\0';i++){
			int x=key[i];
			sum+=x;
		}
		return sum % 100;
	}
	void Add_Record(string key,string value){
		int index=hashFunction(key);
		Node *newD=new Node(key,value);
		
		if(table[index]==nullptr){
			table[index]=newD;
		}
		else{
			Node*temp=table[index];
		table[index]=newD;
		newD->next=temp;
		}
		count++;
	}
	void Word_Search(string key){
		int index=hashFunction(key);

		Node *temp=table[index];
		while(temp){
			if(temp->key==key){
			cout<<temp->key<<":"<<temp->value;
			temp=temp->next;
			return;
			}
		}
		cout<<"Error! Word Not Found";
	
	}
	void remove_Record(string key){
	int index=hashFunction(key);
	Node *temp=table[index];
	Node *prev=nullptr;
		while(temp && temp->key!=key){
			prev=temp;
			temp=temp->next;
		}
		if(temp==nullptr){
			cout<<"Key Not Found";
		}
		if(prev=nullptr){
		table[index]=temp->next;
			
		}else{
			prev->next=temp->next;
		}
		delete temp;
}
	void display(){
		for(int i=0;i<100;i++){
			Node *temp=table[i];
			cout<<i+1<<") ";
			while(temp){
				cout<<temp->key<<":"<<temp->value <<"-> ";
				temp=temp->next;
			}
			cout<<"NULL";
		}
	}
};
int main(){
	DictionaryApp d;
	d.Add_Record("AB","FASTNU");
	d.Add_Record("CD","CS");
	cout<<"Searching AB: "<<endl;
	d.Word_Search("AB");
	cout<<endl;
	cout<<"Displaying: "<<endl;
	d.display();
}