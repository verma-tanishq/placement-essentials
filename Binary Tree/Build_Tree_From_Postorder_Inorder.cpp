#include<iostream>
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

int search(int inorder[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end){
    if(start>end){
        return NULL;
    }
    static int idx = 4;
    int val = inorder[idx];
    idx--;
    Node* curr = new Node(val);
    int pos = search(inorder, start, end, val);

    if(start==end){
        return curr;
    }
    curr->right = buildTree(postorder,inorder,pos+1,end);
    curr->left = buildTree(postorder,inorder,start, pos-1);

    return curr;
}

void inorderSearch(Node* root){
    if(root==NULL){
        return;
    }
    inorderSearch(root->left);
    cout<<root->data<<" ";
    inorderSearch(root->right);
}

int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildTree(postorder,inorder,0,4);
    inorderSearch(root);
    cout<<"\n";
    return 0;
}