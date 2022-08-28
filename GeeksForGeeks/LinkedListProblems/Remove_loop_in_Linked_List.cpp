class Solution
{
    public:
    Node *intersectionPoint(Node *&head){
        if(head==NULL){
            return NULL;
        }
        Node *slow=head;
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
    
    Node *startOfloop(Node *&head){
        if(head==NULL){
            return NULL;
        }
        Node *intersection=intersectionPoint(head);
        if(intersection==NULL){
            return NULL;
        }
        Node *slow=head;
        
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
            
        }
        return slow;
    }
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       Node* start=startOfloop(head);
       if(start==NULL){
           return ;
       }
       Node* temp=start;
       while(temp->next!=start){
           temp=temp->next;
           
       }
       
       temp->next=NULL;
       return ;
    }
};
