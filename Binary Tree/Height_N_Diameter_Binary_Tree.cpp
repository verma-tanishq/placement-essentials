#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftH = calcHeight(root->left);
    int rightH = calcHeight(root->right);

    return max(leftH, rightH) + 1;
}

int calcDiameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftH = calcHeight(root->left);
    int rightH = calcHeight(root->right);
    int currDia = leftH+ rightH+1;

    int lDia = calcDiameter(root->left);
    int rDia = calcDiameter(root->right);

    return max(currDia, max(lDia,rDia));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl;
    return 0;
}