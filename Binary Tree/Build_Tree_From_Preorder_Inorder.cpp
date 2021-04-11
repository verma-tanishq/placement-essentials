#include<iostream>
using namespace std;

class Node{
    public:
    Node* right;
    Node* left;
    int data;
    Node(int val){
        data = val;
        right=NULL;
        left=NULL;
    }
};

int search(int inorder[],int start, int end, int idx){
    for(int i=start; i<=end; i++){
        if(inorder[i]==idx){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preoder[], int inorder[], int start, int end){
    int curr;
    static int idx=0;
    if(start>end){
        return NULL;
    }
    curr = preoder[idx];
    idx++;
    Node* node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preoder, inorder, start, pos-1);
    node->right = buildTree(preoder, inorder, pos+1, end);

    return node;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}