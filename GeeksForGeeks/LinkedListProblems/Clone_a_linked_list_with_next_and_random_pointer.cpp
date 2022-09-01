class Solution
{
    private:
        void insertAtTail(Node* &head,Node* &tail,int data){
            Node* newNode=new Node(data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
    public:
    Node *copyList(Node *head)
    {
         Node* cloneHead=NULL;
         Node* cloneTail=NULL;
         
         Node* temp=head;
         while(temp!=NULL){
             insertAtTail(cloneHead,cloneTail,temp->data);
             temp=temp->next;
         }
         
         Node* originalNode=head;
         Node* cloneNode=cloneHead;
         
         unordered_map<Node*,Node*> mp;
         while(originalNode!=NULL){
             mp[originalNode]=cloneNode;
             originalNode=originalNode->next;
             cloneNode=cloneNode->next;
         }
         
         originalNode=head;
         cloneNode=cloneHead;
         while(originalNode!=NULL){
             cloneNode->arb=mp[originalNode->arb];
             originalNode=originalNode->next;
             cloneNode=cloneNode->next;
         }
         
         return cloneHead;
    }

};
