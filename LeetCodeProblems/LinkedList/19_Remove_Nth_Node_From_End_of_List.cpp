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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* temp=prev;
        ListNode* curr=head;
        
        while(--n){
            curr=curr->next;
        }
        curr=curr->next;
        while(curr!=NULL){
            temp=temp->next;
            curr=curr->next;
        }
        temp->next=temp->next->next;
        return prev->next;
    }
};


