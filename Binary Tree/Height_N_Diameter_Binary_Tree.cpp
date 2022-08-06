#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftNode = heightOfBinaryTree(root->left);
    int rightNode = heightOfBinaryTree(root->right);
    return max(leftNode,rightNode)+1;
}

int DiameterOfBinaryTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int op1 = DiameterOfBinaryTree(root->left);
    int op2 = DiameterOfBinaryTree(root->right);
    int op3 = heightOfBinaryTree(root->left)+heightOfBinaryTree(root->right)+1;

    return max(op1,max(op2,op3));
}


// More Optimize approach TC = O(n)
pair<int,int> diameterFast(Node* root){
    pair<int,int> p = make_pair(0,0);
    if(root==NULL){
        return p;
    }
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second+right.second+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second, right.second)+1;
    return ans;
}

int diameter(Node* root){
    return diameterFast(root).first;
}

int main(){
    // Node* root = new Node(1);
    // root->left  = new Node(12);
    // root->right = new Node(13);
   
    // root->right->left   = new Node(14);
    // root->right->right  = new Node(15);
   
    // root->right->left->left   = new Node(21);
    // root->right->left->right  = new Node(22);
    // root->right->right->left  = new Node(23);
    // root->right->right->right = new Node(24);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //cout<<"Diameter of Binary Tree is: "<<DiameterOfBinaryTree(root);
    cout<<"Diameter of Binary Tree is: "<<diameter(root);
    
    return 0;
}
