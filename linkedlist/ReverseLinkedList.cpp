#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data ;
	Node* next;


	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};

Node* reverseLinkedList(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	Node* forward = NULL;

	if(head==NULL || head->next=NULL){
		return head;
	}

	while(curr!=NULL){
		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;
	}
	return prev;
}

int main(){
	Node* head = NULL;
  return 0;
}
Iterative Approach
TC = O(n)
SC = O(1)

// Recursive Approach
Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
TC = O(n)
SC = O(n)
