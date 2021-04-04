#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int length(node* &head){
    node* temp = head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node* kappend(node* &head, int k){
    node* newTail;
    node* newHead;
    node* tail = head;

    int l=length(head);
    k = k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k+1){
            newHead = tail;
        }
        if(count==l-k){
            newTail = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int value){
    node* n = new node(value);
    node* temp = head;
    if(head==NULL){
        insertAtHead(head, value);
        return;
    }
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtHead(head, 12);
    insertAtTail(head, 54);
    insertAtTail(head, 13);
    insertAtTail(head, 23);
    display(head);
    // deletion(head, 3);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    node* newHead = kappend(head, 2);
    display(newHead);
    
    // display(head);
    return 0;
}