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

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    stack<Node*> st;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        st.push(node);
        q.pop();
        if(node->right!=NULL){
            q.push(node->right);
        }
        if(node->left!=NULL){
            q.push(node->left);
        }
    }
    while(!st.empty()){
        root = st.top();
        cout<<root->data<<" ";
        st.pop();
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    LevelOrderTraversal(root);
    return 0;
}

// Output 3 2 1
