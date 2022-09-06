class Solution
{
private:
    void insertAtTail(struct Node* &head,struct Node* &tail,int digit){
    Node* nodeToInsert=new Node(digit);
    if(head==NULL){
        head=nodeToInsert;
        tail=nodeToInsert;
        return;
    }
    else{
        tail->next=nodeToInsert;
        tail=nodeToInsert;
        
    }
}


Node* add(struct Node* first, struct Node* second){
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }
        
        int sum=carry+val1+val2;
        int digit=sum%10;
        
        insertAtTail(ansHead,ansTail,digit);
        
        carry=sum/10;
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
        
        
    }
    return ansHead;
}
Node* reverse(struct Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node*forward=NULL;
    
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
    
}
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
    }
};
