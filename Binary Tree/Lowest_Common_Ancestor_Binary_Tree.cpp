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
//O(n)
//<------------------------------------------------------------------------------------->
// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>

using namespace std;

// A Binary Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
	// base case
	if (root == NULL) return false;

	// Store this node in path vector. The node will be removed if
	// not in path from root to k
	path.push_back(root->key);

	// See if the k is same as root's key
	if (root->key == k)
		return true;

	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
		(root->right && findPath(root->right, path, k)) )
		return true;

	// If not present in subtree rooted with root, remove root from
	// path[] and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<int> path1, path2;

	// Find paths from root to n1 and root to n1. If either n1 or n2
	// is not present, return -1
	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	/* Compare the paths to get the first different value */
	int i;
	for (i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i] != path2[i])
			break;
	return path1[i-1];
}

// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}
