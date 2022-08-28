class Solution{
    public:
    int getLength(Node *head){
        Node* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        int len=getLength(head);
        Node* ptr=head;
        int cnt=0;
        int middle=(len/2);
        while(cnt!=middle){
            ptr=ptr->next;
            cnt++;
        }
        return ptr->data;
    }
};
