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
    }
};

Node* insertAtBinaryTree(Node* root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(root->data>key){
        root->left = insertAtBinaryTree(root->left, key);
    }
    if(root->data<key){
        root->right = insertAtBinaryTree(root->right, key);
    }
    return root;
}

void inoreder(Node* root){
    if(root==NULL){
        return;
    }
    inoreder(root->left);
    cout<<root->data<<" ";
    inoreder(root->right);
}

int main(){
    Node* root = NULL;
    root = insertAtBinaryTree(root,5);
    insertAtBinaryTree(root,1);
    insertAtBinaryTree(root,3);
    insertAtBinaryTree(root,4);
    insertAtBinaryTree(root,2);
    insertAtBinaryTree(root,7);

    inoreder(root);
    return 0;
}
//O(logn)
<----------------------------------------------------------------------------------------------->
// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root)
	{
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data)
	{
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else
	{
		// Insert left node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}

