// Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1} 
// 1) We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the end of postorder traversal.
// 2) We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree. 

//          1
//        /    \
// [4, 8, 2, 5]   [6, 3, 7]
// 3) We recur the above process for following two. 
// ….b) Recur for in[] = {6, 3, 7} and post[] = {6, 7, 3} 
// …….Make the created tree as right child of root. 
// ….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}. 
// …….Make the created tree as left child of root.

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
