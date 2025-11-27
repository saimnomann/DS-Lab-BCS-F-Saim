#include<iostream>
using namespace std;
struct Node{
int data;
Node *left;
Node *right;
int height;
Node(int val){
data=val;
left=nullptr;
right=nullptr;
height=1;
}	
};
Node *insertBST(Node *root,int key){
	if(root==nullptr)
	return new Node(key);
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	else if(key>root->data){
		root->right=insertBST(root->right,key);
	}	
	return root;
}
int get_height(Node *node){
	if(node==nullptr)return 0;
	return node->height;
}
int update_height(Node *node){
	int lh=get_height(node->left);
	int rh=get_height(node->right);
	return 1+max(lh,rh);
}
int get_balance(Node *node){
	if(node==nullptr)return 0;
	return get_height(node->left)-get_height(node->right);
}
Node *convertBSTA(Node *root){
	Node *x=root->left;
	Node *T2=x->right;
	
	x->right=root;
	root->left=T2;
	
	update_height(root);
	update_height(x);
	return x;
}
Node *convertBSTB(Node *root){
	Node *x=root->right;
	Node *T2=x->left;
	
	x->left=root;
	root->right=T2;
	
	update_height(root);
	update_height(x);
	
	return x;
}
void inorder(Node *root){
	if(root==nullptr)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}
int main(){
	Node *bstA=nullptr;
	Node *bstB=nullptr;
	bstA=insertBST(bstA,10);
	bstA=insertBST(bstA,6);
	bstA=insertBST(bstA,4);
	bstA=insertBST(bstA,8);
	
	bstA=convertBSTA(bstA);
	
	cout<<"Inorder AVL A: "<<endl;
	inorder(bstA);
	
	bstB=insertBST(bstB,10);
	bstB=insertBST(bstB,16);
	bstB=insertBST(bstB,12);
	bstB=insertBST(bstB,18);
	
	bstB=convertBSTB(bstB);
	
	cout<<endl;
	cout<<"Inorder AVL B: "<<endl;
	inorder(bstB);
}

//Why AVL?
//AVL trees keep the height balanced so searching always stays O(log n).
//Without balancing, BSTs can become skewed AND slow like linked lists.

//What rotation is performed?
//
//BST-A is left-heavy → Right Rotation is performed.
//
//BST-B is right-heavy → Left Rotation is performed.

//For BST A:
//How links change
//
//x->right = root → node 6 becomes parent, node 10 moves down to the right.
//
//root->left = T2 → node 10’s left child becomes subtree 8.
//
//This forms the balanced AVL: 6 as root, 4 on left, 10 on right with 8 under 10.
//
//Why return x? 
//
//After rotation, x becomes the new root of the AVL subtree.
//
//Returning x ensures the caller receives the balanced tree’s root.
//
//The old root (y) is moved downward and is no longer at the top.
//
//Returning the new root is necessary so the updated structure does not get lost.


//LEFT ROTATION (BST-B)

//Pointer Meaning
//root = y = unbalanced node (10).
//
//x = root->right = child causing imbalance (16).
//
//T2 = x->left = middle subtree between x and y (12).
//
//How links change
//
//x->left = root → node 16 becomes parent, node 10 moves down to the left.
//
//root->right = T2 → node 10’s right child becomes subtree 12.
//
//This forms the balanced AVL: 16 as root, 10 left, 18 right with 12 below 10.
//
//Why return x?
//
//After left rotation, x is the new AVL root.
//
//The rotation makes x the top node because it balances the right-heavy tree.
//
//The original root is pushed down but still kept inside the tree.
//
//Returning x guarantees the AVL structure is preserved correctly.