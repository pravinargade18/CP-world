/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL){
        return NULL;
    }
    unordered_map<int,bool>mp;
    mp[head->data]=true;
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=NULL){
        if(mp[curr->data]==true){
            prev->next=curr->next;
            delete(curr);
        }
        else{
            mp[curr->data]=true;
             prev=curr;
        }
        curr=prev->next;
    }
    return head;
}
