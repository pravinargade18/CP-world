Node* deleteNode(Node *head,int x)
{
    if(x==1){
        head=head->next;
        return head;
    }
    
    Node * prev=NULL;
    Node * curr=head;
    int i=1;
    while(i<x){
        prev=curr;
        curr=curr->next;
        i++;
    }
    prev->next=curr->next;
    delete(curr);
    return head;
}
