#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void printLinkedList(Node* n){
    while (n!=NULL){
        cout<<n->data <<" ";
        n = n->next;
    }
}



int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();


    head->data = 1;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 1234;
    third->next = NULL;

    printLinkedList(head);
    return 0;
}


<---------------------------------------------------------------------------------------------->

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
void insertAtBeginning(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void 

void printLinkedList(Node* n){
    while (n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main(){
    Node* head = NULL;
    Node* second = NULL;

    head = new Node();
    second = new Node();
    
    head->data = 124;
    head->next = second;

    second->data = 543;
    second->next = NULL;

    
    cout<<"Calling insertAtBeginning fun()"<<endl;
    insertAtBeginning(&head, 45);
    cout<<"After insertAtBeginning fun()"<<endl;
    printLinkedList(head);
    return 0;
}

<---------------------------------------------------------------------------->

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(node* &head, int value){
    node* n = new node(value);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteNode(node* &head, int value){
    node* temp = head;
    while(temp->next->data!=value){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete(todelete);
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
}

node* reverseLinkedList(node* &head){  //iterative approach
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

node* revusingrecursion(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead = revusingrecursion(head->next);
    head->next->next=head;
    head->next = NULL;

    return newHead;
}

node* revK(node* &head, int k){
    node* preptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr; 
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = revK(nextptr, k);
    }
    return preptr;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head =NULL;
    insertAtTail(head, 12);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 30);
    insertAtTail(head, 10);
    display(head);
    insertAtHead(head, 50);
    display(head);
    deleteNode(head, 1);
    display(head);
    deleteAtHead(head);
    display(head);
    cout<<search(head, 50)<<endl;

    
    node* newhead = revusingrecursion(head);
    display(newhead);

    node* newhead = revK(head, 2);
    display(newhead);
    return 0;
}
