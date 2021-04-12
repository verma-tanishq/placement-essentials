#include<iostream>
using namespace std;

class Node{
    public:
    Node* right;
    Node* left;
    int data;
    Node(int val){
        data=val;
        right=NULL;
    }
};

Node* insertAtBinaryTree(Node* root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(root->data>key){
        root->left = insertAtBinaryTree(root->left, key);
    }
    if(root->data<key){
        root->right = insertAtBinaryTree(root->right, key);
    }
    return root;
}

void inoreder(Node* root){
    if(root==NULL){
        return;
    }
    inoreder(root->left);
    cout<<root->data<<" ";
    inoreder(root->right);
}

int main(){
    Node* root = NULL;
    root = insertAtBinaryTree(root,5);
    insertAtBinaryTree(root,1);
    insertAtBinaryTree(root,3);
    insertAtBinaryTree(root,4);
    insertAtBinaryTree(root,2);
    insertAtBinaryTree(root,7);

    inoreder(root);
    return 0;
}
