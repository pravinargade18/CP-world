Node* insertInMiddle(Node* head, int x)
{
    Node* slow=head;
    Node* fast=head;
    Node* nodeToInsert=new Node(x);
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
    }
    nodeToInsert->next=slow->next;
    slow->next=nodeToInsert;
    return head;
    
    
}
