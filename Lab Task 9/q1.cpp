#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *right;
	Node *left;
	int height;
	Node(int val){
		data=val;
		right=nullptr;
		left=nullptr;
		height=1;
	}
};
class AVL{
	public:
	Node *root;
		AVL(){
			root=nullptr;
		}
int get_height(Node *node){
	if(node==nullptr)return 0;
	return node->height;
}
int get_balance(Node *node){
	if(node==nullptr)return 0;
	return get_height(node->left)-get_height(node->right);
}
void update_height(Node *node){
	int lh=get_height(node->left);
	int rh=get_height(node->right);
	node->height=1+max(lh,rh);
}
Node *rightRotate(Node *root){
	Node *x=root->left;
	Node *T2=x->right;
	
	x->right=root;
	root->left=T2;
	
	update_height(root);
	update_height(x);
	
	return x;
}
Node *leftRotate(Node *root){
	Node *x=root->right;
	Node *T2=x->left;
	
	x->left=root;
	root->right=T2;
	
	update_height(root);
	update_height(x);
	
	return x;
}
Node *balance(Node *node){
	int balance=get_balance(node);
	
	if(balance>1 && get_balance(node->left)>=0){
		return rightRotate(node);
	}
	if(balance>1 && get_balance(node->right)<=0){
		root->left=leftRotate(node->left);
		return rightRotate(node);	
	}
	if(balance<1 && get_balance(node->right)<=0){
		return leftRotate(node);
	}
	if(balance<1 && get_balance(node->right)>=0){
		root->right=rightRotate(node->right);
		return leftRotate(node); 
	}
	return node;
}
Node *insert(Node *root,int val){
	if(root==nullptr){return new Node(val);
	}
	if(val<root->data){
		root->left=insert(root->left,val);
	}
	else if(val>root->data){
		root->right=insert(root->right,val);
	}
	else{
		return root;
	}
	update_height(root);
	return balance(root);
}
void inorder(Node *root){
	if(root==nullptr){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
};
int main(){
	AVL tree;
	int elements[] = {50,30,70,20,40,60,80};
	for(int i=0;i<7;i++)
	tree.root=tree.insert(tree.root,elements[i]);
	
	cout<<"Inorder AVL Tree before 55 insertion: "<<endl;
	tree.inorder(tree.root);
	cout<<endl;
	
    tree.root = tree.insert(tree.root, 55);
    cout << "Inorder AVL Tree after inserting 55: " << endl;
    tree.inorder(tree.root);
    cout << endl;

    // Perform left rotation on root
    tree.root = tree.leftRotate(tree.root);
    cout << "Inorder AVL Tree after left rotation on root: " << endl;
    tree.inorder(tree.root);
    cout << endl;

    return 0;

}