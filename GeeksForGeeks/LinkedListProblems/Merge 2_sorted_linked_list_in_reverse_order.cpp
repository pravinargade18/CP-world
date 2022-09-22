

/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

    
Node* merge(Node* first ,Node* second){
    Node* dummy=new Node();
    Node* temp=dummy;
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            temp->next=first;
            temp=first;
            first=first->next;
        }
        else{
            temp->next=second;
            temp=second;
            second=second->next;
        }
    }
    if(first!=NULL){
        temp->next=first;
    }
    if(second!=NULL){
        temp->next=second;
    }
    return dummy->next;
}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

struct Node * mergeResult(Node *node1,Node *node2)
{
    if(node1==NULL){
        return reverse(node2);
    }
    if(node2==NULL){
        return reverse(node1);
    }
    
    if(node1->data<=node2->data){
        Node* first=merge(node1,node2);
        return reverse(first);
    }
    else{
         Node* second=merge(node2,node1);
        return reverse(second);
    }
    
}
