//Iterative approach
int getLength(Node* head){
    int l=0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

Node *findMiddle(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    int len = getLength(head);
    int mid = len/2;
    int cnt = 0;
    Node* temp = head;
    while(cnt<mid){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
