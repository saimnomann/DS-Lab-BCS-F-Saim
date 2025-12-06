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
class HashTable{
	Node **table;
	int tableSize;
	int bucketsNum=10;
	public:
		HashTable(){
			table=new Node *[bucketsNum];
			for(int i=0;i<bucketsNum;i++){
				table[i]=nullptr;
			}
		}
		int hashFunction(string key){
			int sum=0;
			for(int i=0;key[i]!='\0';i++){
				int x=key[i];
				sum+=x;
				
			}
			return sum % bucketsNum;
		}
		void insert(string key,string value){
			int id=hashFunction(key);
			Node *newS=new Node(key,value);
			if(table[id]==nullptr){
			table[id]=newS;
			}
	else{
			Node *temp=table[id];
	table[id]=newS;
	newS->next=temp;
			}
		}
	void display(){
for(int i=0;i<bucketsNum;i++)
{
	cout<<i+1<<") ";
	Node *temp=table[i];
	while(temp){
		cout<<"Key : "<<temp->key<<" Value : "<<temp->value<<"-> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
}
};
int main(){
	HashTable myhash;
    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");
    
    myhash.display();
}
