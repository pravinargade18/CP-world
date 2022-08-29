/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* intersectionPoint(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
Node *startingPoint(Node *head){
    
    if(head==NULL){
        return NULL;
    }
    Node* intersection=intersectionPoint(head);
     Node*slow=head;
    if(intersection==NULL){
        return NULL;
    }
   
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head==NULL){
return NULL;}
    Node *startOfLoop=startingPoint(head);
    if(startOfLoop==NULL){
        return head;
    }
    Node*temp=startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
