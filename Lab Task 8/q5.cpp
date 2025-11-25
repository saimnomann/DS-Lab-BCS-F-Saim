#include<iostream>
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
class BST{
public:
	Node *root;
	BST(){
		root=nullptr;
	}
};
bool checkBST(Node *root,int minVal,int maxVal){
	if(root==nullptr){
		return true;
	}
	if(root->data<=minVal || root->data>=maxVal)return false;
	return checkBST(root->left,minVal,root->data) && checkBST(root->right,root->data,maxVal);
}
int main(){
	BST bst1,bst2,bst3;
	//Constructing a Sample BST
	bst1.root=new Node(10);
	bst1.root->left=new Node (5);
	bst1.root->right=new Node(20);
	bst1.root->right->left=new Node(25);
	bst1.root->right->right=new Node(30);
	cout<<(checkBST(bst1.root,-1e9,1e9)?"Is A BST ":"Not A BST")<<endl;
	
	//Figure 1
	bst2.root=new Node (2);
	bst2.root->left=new Node (1);
	bst2.root->right=new Node (3);
	bst2.root->right->right=new Node (5);
	cout<<(checkBST(bst2.root,-1e9,1e9)?"Is A BST ":"Not A BST")<<endl;
	
	//Figure 2
	bst3.root=new Node(10);
	bst3.root->left=new Node (5);
	bst3.root->right=new Node(20);
	bst3.root->right->left=new Node(9);
	bst3.root->right->right=new Node(25);
	cout<<(checkBST(bst3.root,-1e9,1e9)?"Is A BST ":"Not A BST")<<endl;
	
}