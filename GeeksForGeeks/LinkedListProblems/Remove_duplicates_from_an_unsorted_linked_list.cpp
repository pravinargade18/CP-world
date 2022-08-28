class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,bool>mp;
        mp[head->data]=true;
        Node *prev=head;
        Node *curr=head->next;
        while(curr!=NULL){
            if(mp[curr->data]==true){
                prev->next=curr->next;
                delete(curr);
            }
            else{
                mp[curr->data]=true;
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};
