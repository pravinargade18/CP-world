class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head==NULL){
            return false;
        }
        // your code here
        Node *slow=head;
        Node *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow){
                return true;
            }
        }
        return false;
        
        
    }
};
