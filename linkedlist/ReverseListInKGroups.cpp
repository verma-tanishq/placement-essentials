Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int cnt = 0;
    while(curr!=NULL && cnt<k){
        forward = curr->next;
        curr->next = prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    if(forward!=NULL){
        head->next = kReverse(forward, k);
    }
    return prev;
}

// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0
