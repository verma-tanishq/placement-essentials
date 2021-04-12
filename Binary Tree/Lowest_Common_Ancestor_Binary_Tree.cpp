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
        left=NULL;
    }
};

Node* LCA2(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    Node* leftLCA = LCA2(root->left,n1,n2);
    Node* rightLCA = LCA2(root->right, n1,n2);
    if(root->data==n1 || root->data==n2){
        return root;
    }
    
    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }
    return rightLCA;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int n1 = 7;
    int n2 = 6;
    Node* LCA = LCA2(root,n1,n2);
    if(LCA){
        cout<<"LCA: "<<LCA->data<<endl;
    }
    else{
        cout<<"LCA doesn't exit\n";
    }


    return 0;
}