#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    unsigned frq;
    MinHeapNode *left; 
    MinHeapNode *right;
    MinHeapNode(char data, unsigned frq){
        left=right=NULL;
        this->data = data;
        this->frq = frq;
    }
};

struct comp{
    bool operator()(MinHeapNode *l, MinHeapNode *r){
        return l->frq > r->frq;
    }
};

void printHuff(struct MinHeapNode* root, string str){
    if(!root){
        return; 
    }
    if(root->data!='$'){
        cout<<root->data<<": "<<str<<"\n";
    }
    printHuff(root->left, str+"0");
    printHuff(root->right, str+"1");
}

void huffmanCode(char data[], int frq[], int n){
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, comp> minHeap;

    for(int i=0; i<n; ++i){
        minHeap.push(new MinHeapNode(data[i], frq[i]));
    }
    while(minHeap.size()!=1){
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->frq + right->frq);
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    printHuff(minHeap.top(),"");


}

int main(){
    char arr[] = {'a','b','c','d','e','f'};
    int frq[] = {5,9,12,13,16,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    huffmanCode(arr,frq,n);
    return 0;
}

