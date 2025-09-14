#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data=val;
        next = nullptr;
        child = nullptr;
    }
};

Node* flatten(Node* head) {
    if (head==NULL){
        return nullptr;
    }
    Node* curr = head;
    while (curr!=NULL) {
        if (curr->child) {
            Node* next=curr->next;
            curr->next=curr->child;
            curr->child=NULL;
            Node* tail=curr->next;
            while(tail->next){
                tail=tail->next;
            }
            tail->next=next;
        }
        curr =curr->next;
    }
    return head;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n2->child = n4;
    n4->next = n5;
    Node* flat = flatten(n1);
    Node* curr = flat;
    while (curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}