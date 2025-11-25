#include<iostream>
using namespace std;
class Combatant{
	public:
	string name;
	int hp;
	int attackPower;
	Combatant(){
		name="";
		hp=0;
		attackPower=0;
	}
	Combatant(string n,int h,int a){
			name=n;
			hp=h;
			attackPower=a;
		}
	void display(){
		cout<<"Name : "<<name<<" HP : "<<hp<<" Attack Power : "<<attackPower<<endl;
	}
};
struct Node{
	Combatant *data;
	Node *left;
	Node *right;
	Node(const Combatant &obj){
		data=new Combatant(obj);
		left=nullptr;
		right=nullptr;
	}
	
};
Node* insertNode(Node *root,Combatant c){
		if(root==nullptr){
		return new Node(c);
		}
		if(c.name<root->data->name){
			root->left=insertNode(root->left,c);
		}
		else if(c.name>root->data->name){
			root->right=insertNode(root->right,c);
		}
	return root;	
	}
	Node *findMin(Node *root){
	while(root && root->left)
	root=root->left;
	return root;
}
	Node *deleteNode(Node *root,string name){
		if(root==nullptr)return nullptr;
		if(name<root->data->name)root->left=deleteNode(root->left,name);
		else if(name>root->data->name)root->right=deleteNode(root->right,name);
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
	root->data->name=temp->data->name;
	root->data->attackPower=temp->data->attackPower;
	root->data->hp=temp->data->hp;
	root->right=deleteNode(root->right,temp->data->name);
	}
	return root;
	}
	Node *getFrontLine(Node *root){
		while(root && root->left){
			root=root->left;
		}
		return root;
	}
	void inorder(Node *root){
		if(root==nullptr)return;
		inorder(root->left);
		root->data->display();
		inorder(root->right);
	}
class BST{
	public:
	Node *root;
		BST(){
		root=nullptr;	
		}
	void insert(Combatant c){
		root=insertNode(root,c);
	}
	void remove(string name){
		root=deleteNode(root,name);
	}
	void display(){
		inorder(root);
	}
	Node* getFrontline(Node *root){
		return root;
	}
	
};
int main(){
	BST heroes,enemies;
	heroes.insert(Combatant("Saim", 20, 5));
    heroes.insert(Combatant("Rafay", 18, 6));
    heroes.insert(Combatant("Maarij", 15, 7));
    heroes.insert(Combatant("Huzaifa", 22, 4));
    heroes.insert(Combatant("Ali", 12, 3));
    
    enemies.insert(Combatant("Ebad", 10, 4));
    enemies.insert(Combatant("Abid", 14, 5));
    enemies.insert(Combatant("Asim", 16, 3));
    enemies.insert(Combatant("Naeem", 12, 2));
    enemies.insert(Combatant("Saad", 18, 4));
	
	int round=1;
	while(heroes.root!=nullptr && enemies.root!=nullptr){
	cout<<"Round "<<round<<endl;
	cout<<"Player Team : "<<endl;
	heroes.display();
	cout<<"Enemy Team : "<<endl;
	enemies.display();
	Node *heroFront=heroes.getFrontline(heroes.root);
	Node *enemyFront=enemies.getFrontline(enemies.root);
	
	  int damage = heroFront->data->attackPower + rand() % 5;
    enemyFront->data->hp -= damage;
    cout << heroFront->data->name << " attacks " << enemyFront->data->name
         << " for " << damage << " damage.\n";
    if (enemyFront->data->hp <= 0) {
        cout << enemyFront->data->name << " is defeated!\n";
        enemies.remove(enemyFront->data->name);
    }

    if (enemies.root != nullptr) {
        heroFront = heroes.getFrontline(heroes.root);
        enemyFront = enemies.getFrontline(enemies.root);
        damage = enemyFront->data->attackPower + rand() % 5;
        heroFront->data->hp -= damage;
        cout << enemyFront->data->name << " attacks " << heroFront->data->name
             << " for " << damage << " damage.\n";
        if (heroFront->data->hp <= 0) {
            cout << heroFront->data->name << " is defeated!\n";
            heroes.remove(heroFront->data->name);
        }
    }

    round++;
}

if (heroes.root == nullptr) cout << "Enemies win!\n";
else cout << "Heroes win!\n";
	
}