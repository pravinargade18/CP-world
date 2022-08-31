Node* deleteMid(Node* head)
{
   Node *slow =head;
   Node* fast=head;
   Node *prev=NULL;
   while(fast!=NULL && fast->next!=NULL){
       prev=slow;
       slow=slow->next;
       fast=fast->next->next;
   }
   prev->next=slow->next;
   delete(slow);
   return head;  
   
   
}
