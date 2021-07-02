#include <bits/stdc++.h>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int val;
    Node *left, *right;
 
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};
 
// Function to find the diameter of the binary tree. Note that the function
// returns the height of the subtree rooted at a given node, and the diameter
// is updated within the function as it is passed by reference

int Solve(Node* root, int& res) {
    if (root == NULL)
        return 0;
        
    int l = Solve(root->left, res);
    int r = Solve(root->right, res);
    
    int temp = max(root->val + max(l, r), root->val);
    int ans = max(temp, l + r + root->val);
    
    res = max(res, ans);
    return temp;
}
int maxPathSum(Node* root) {
    int res = INT_MIN;
    Solve(root, res);
    return res;
}
 
int main()
{
    Node *root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
 
    cout << "The diameter of the tree is " << maxPathSum(root);
 
    return 0;
}
