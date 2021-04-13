#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, end);

        for(int j=0; j<leftSubtrees.size(); j++){
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    } 
    return trees;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<Node*> totalTrees = constructTrees(1,3);
    for(int i=0; i<totalTrees.size(); i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}
/* Output
1 : 123
2 : 132
3 : 213
4 : 312
5 : 321
*/
// C++ dynamic programming implementation of the approach
#include <iostream>
using namespace std;

// Function to return the count
// of unique BSTs with n keys
int uniqueBSTs(int n)
{
	// construct a dp array to store the
	// subsequent results
	int dparray[n + 1] = { 0 };

	// there is only one combination to construct a
	// BST out of a sequence of
	dparray[0] = dparray[1] = 1;
	
	// length 1 (only a root) or 0 (empty tree).
	for (int i = 2; i <= n; ++i)
	{
		// choosing every value as root
		for (int k = 1; k <= i; ++k)
		{
			dparray[i] += dparray[k - 1] * dparray[i - k];
		}
	}
	return dparray[n];
}

// Driver code
int main()
{
	int n = 2;

	// Function call
	cout << uniqueBSTs(n);

	return 0;
}
// Time Complexity O(n^2)
// Space Complexity O(n)
