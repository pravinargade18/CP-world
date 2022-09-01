/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        
        k=k%cnt;
        while(k--){
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL && curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
            prev->next=NULL;
            curr->next=head;
            head=curr;
        }
        return head;
        
    }
};
