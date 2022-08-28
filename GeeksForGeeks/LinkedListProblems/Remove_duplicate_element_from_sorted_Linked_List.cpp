Node *removeDuplicates(Node *head)
{
    Node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node *nodeToPoint=temp->next->next;
            Node *nodeToDelete=temp->next;
            delete(nodeToDelete);
            temp->next=nodeToPoint;
           
        }
        else{
             temp=temp->next;
        }
    }
    return head;
}
