#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
 
Node* mirrorTree(Node* root){
    if(root==NULL){
        return root;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    if(root->left){
        mirrorTree(root->left);
    }
    if(root->right){
        mirrorTree(root->right);
    }
    return root;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    inorder(root);                        // 3 4 1 5 2 6 
    cout<<endl;
    mirrorTree(root);         
    inorder(root);                       // 6 2 5 1 4 3
    return 0;
}
