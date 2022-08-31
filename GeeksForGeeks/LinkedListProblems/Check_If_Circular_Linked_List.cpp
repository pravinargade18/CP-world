bool isCircular(Node *head)
{
   Node* temp=head;
   while(temp->next!=head && temp->next!=NULL){
       temp=temp->next;
   }
   if(temp->next==head){
       return true;
   }
   if(temp->next==NULL){
       return false;
   }
   
}
