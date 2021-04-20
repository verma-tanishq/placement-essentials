#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

void topView(Node* root){
    if(root==NULL){
        return;
    }
    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int> m;
    while(!q.empty()){
        Node* curr = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!m[h]){
            m[h] = curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left,h-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,h+1});
        }
    }
    for(auto i:m){
        cout<<i.second<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //right view
    topView(root);
    return 0;
}