#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        right = left = NULL;
    }
};

void printLevel(Node* root){
    queue<Node*> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int sumAtK(Node* root, int k){
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level = 0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printLevel(root);
    cout<<sumAtK(root,2);  //output =>22 (4+5+6+7)
    return 0;
}
