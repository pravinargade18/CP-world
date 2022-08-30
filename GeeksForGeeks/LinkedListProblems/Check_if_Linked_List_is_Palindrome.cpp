class Solution{
  private:
        Node *getMid(Node *head){
            Node* slow=head;
            Node* fast=head;
            
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                
            }
            return slow;
        }
        
        Node *reverse(Node *head){
            Node* curr=head;
            Node* prev=NULL;
            Node* forward=NULL;
            
            while(curr!=NULL){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
            }
            return prev;
        }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        
        if(head->next==NULL){
            return true;
        }
        Node* middle=getMid(head);
        
        Node* temp=middle->next;
        middle->next=reverse(temp);      //
        
        Node* head1=head;
        Node* head2=middle->next;
        
        while(head2!=NULL){
            if(head1->data!=head2->data){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        
        
        return true;
        
    }
};
