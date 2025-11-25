#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int val){
		data=val;
		left=nullptr;
		right=nullptr;
	}
};
Node* insertBST(Node *root,int key){
	if(root==nullptr){
		return new Node(key);
		}
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	if(key>root->data){
		root->right=insertBST(root->right,key);
	}
	return root;
}
void inorder(Node *root){
	if(root==nullptr)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(Node *root){
	if(root==nullptr)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node *root){
	if(root==nullptr)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void levelorder(Node *root){
	if(root==nullptr)return;
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		Node *curr=q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left)q.push(curr->left);
		if(curr->right)q.push(curr->right);
	}
}
bool searchBST(Node *root,int key){
	if(root==nullptr)return false;
	if(root->data==key)return true;
	else if(key<root->data)return searchBST(root->left,key);
	else return searchBST(root->right,key);
}
Node *findMin(Node *root){
	while(root && root->left)
	root=root->left;
	return root;
}
Node *deleteBST(Node *root,int key){
	if(root==nullptr)return root;
	if(key<root->data)root->left=deleteBST(root->left,key);
	else if(key>root->data)root->right=deleteBST(root->right,key);
	else{
		if(root->left==nullptr && root->right==nullptr){
			delete root;
			return nullptr;
		}
		else if(root->left==nullptr){
			Node *temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==nullptr){
			Node *temp=root->left;
			delete root;
			return temp;
		}
	Node *temp=findMin(root->right);
	root->data=temp->data;
	root->right=deleteBST(root->right,temp->data);
	}
	return root;
}
int main(){
	Node *root=nullptr;
	int values[]={50, 30, 70, 20, 40, 60, 80};
	for(int i=0;i<7;i++){
		root=insertBST(root,values[i]);
	}
	cout<<"In Order Traversal : "<<endl;
	inorder(root);
	cout<<endl;
	cout<<"Post Order Traversal : "<<endl;
	postorder(root);
	cout<<endl;
	cout<<"Pre Order Traversal : "<<endl;
	preorder(root);
	cout<<endl;
	cout<<"Level Order Traversal : "<<endl;
	levelorder(root);
	
	int key=60;
	cout<<endl;
	cout<<"Search "<<key <<" : ";
	cout<<(searchBST(root,key)?"Found ": "Not Found")<<endl;
	
	root=deleteBST(root,20);
	cout<<"After Deleting 20 (Inorder) : "<<endl;
	inorder(root);
	cout<<endl;
}