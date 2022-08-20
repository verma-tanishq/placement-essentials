#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtPos(Node* &head, int pos, int val){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    Node* temp = head;
    int cnt= 1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(head,val);
        return;
    }

    Node* nodeToInsert = new Node(val);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteNode(Node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            prev = curr;
            cnt++;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = new Node(100);
    insertAtTail(head, 12);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 30);
    insertAtTail(head, 10);
    display(head);
    cout<<endl;
    insertAtHead(head, 50);
    insertAtPos(head,3,132);
    insertAtPos(head,1,12);
    insertAtPos(head,10,2345);
    display(head);
    cout<<endl;
    deleteNode(head, 5);
    display(head);
    cout<<endl;
    deleteAtHead(head);
    display(head);
    return 0;
}
