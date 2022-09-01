Node* intersectionPoint(struct Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* startOfLoop(struct Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection=intersectionPoint(head);
    if(intersection==NULL){
        return NULL;
    }
    
    Node *slow=head;
    while(intersection!=slow){
        intersection=intersection->next;
        slow=slow->next;
    }
    
    return slow;
    
}





//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    
    Node *start=startOfLoop(head);
    if(start==NULL){
        return 0;
    }
    
    else{
        Node* temp=start;
        int cnt=1;
        while(temp->next!=start){
            cnt++;
            temp=temp->next;
        }
        return cnt;
        
    }
}
