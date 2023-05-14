

/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
void sort(Node **head)
{
     // Code here
     Node* ptr1=*head;
     Node* ptr2=(*head)->next;
     
     while(ptr1->next!=NULL || ptr2!=NULL){
         if(ptr1->data>ptr2->data){
             swap(ptr1->data,ptr2->data);
         }
         ptr2=ptr2->next;
         if(ptr2==NULL){
             ptr1=ptr1->next;
             ptr2=ptr1->next;
         }
     }
     
}
