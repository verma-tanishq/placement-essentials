// https://practice.geeksforgeeks.org/problems/burning-tree/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
//create nodeToparent mapping,find target node,burn the tree in min time
class Solution {
   
   private:
   Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent){
       Node* targetNode = NULL;
       queue<Node*> q;
       q.push(root);
       nodeToParent[root] = NULL; //since parent of root is null
       while(!q.empty()){ //make a level order traversal and create parent mapping, find target node
           Node* front = q.front();
           q.pop();
           
           if(front->data==target){ //target check
               targetNode = front;
           }
           if(front->left){  //adding left node to queue and creating parent mapping
               nodeToParent[front->left] = front;
               q.push(front->left);
           }
           if(front->right){
               nodeToParent[front->right] = front;
               q.push(front->right);
           }
       }
       return targetNode;
   }
   
   private:
   int burnTree(Node* root,map<Node*,Node*> &nodeToParent){ //root is target node initially
       map<Node*,bool> visited; // visited map is needed to keep track of nodes while traversing
       int timeTaken=0;
       queue<Node*> q;
       q.push(root); //target node is in queue initially now the burning starts
       
       while(!q.empty()){
           bool isAdditionDone = false;//need to maitain this in order to track time taken
           int size = q.size(); //need to take size in order to process nodes neighbours only
           for(int i=0;i<size;i++){
               //process neighbouring nodes
               Node* front = q.front();
               q.pop();
               //left,right and parent are the possible neighbours. make sure u mark nodes visited once visited
               if(front->left and !visited[front->left]){ //left neighbour check
                   visited[front->left]= true;
                   isAdditionDone = true;
                   q.push(front->left);
               }
               if(front->right and !visited[front->right]){ //right neighbour check
                   visited[front->right]= true;
                    isAdditionDone = true;
                   q.push(front->right);
               }
               if(nodeToParent[front] and !visited[nodeToParent[front]]){ //parent neighbour check
                   visited[nodeToParent[front]] = true;
                    isAdditionDone = true;
                   q.push(nodeToParent[front]);
               }
           }
           if( isAdditionDone == true){ //3 nodes can also be burnt in 1 second, counted as 1 second
               timeTaken++;
           }
       }
       return timeTaken;
   }
   
   public:
   int minTime(Node* root, int target) 
   {
       int ans=0;
       map<Node*,Node*> nodeToParent; //so that we get to know each node's parent
       Node *targetNode = createParentMapping(root,target,nodeToParent); //creates parent node mapping and finds targetNode
       return burnTree(targetNode,nodeToParent);
   }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
