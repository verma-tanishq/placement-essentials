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

class queue{
    public:
    node* front;
    node* back;
    queue(){
        front=NULL;
        back=NULL;
    }

    void enqueue(int x){
        node* n = new node(x);
        if(front==NULL){
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }

    void dequeue(){
        node* todelete;
        if(front==NULL){
            cout<<"Queue underflow\n";
            return;
        }
        todelete = front;
        front = front->next;
        if(front==NULL){
            back=NULL;
        }
        delete todelete;
    }
    bool empty();
    int peek();
};

bool queue::empty(void){
    if(front==NULL){
        return true;
    }
    return false;
}

int queue::peek(void){
    if(front==NULL){
        cout<<"No element in queue\n";
        return -1;
    }
    return front->data;
}

int main(){
    queue q;
    q.enqueue(12);
    cout<<q.peek()<<endl;

    q.enqueue(129);
    q.dequeue();
    cout<<q.peek()<<endl;
    
    q.enqueue(11);
    cout<<q.peek()<<endl;
    
    q.enqueue(14);
    cout<<q.peek()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;
    
    return 0;
}