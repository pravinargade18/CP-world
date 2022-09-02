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
private:
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(first!=NULL && second!=NULL){
            if(first->val<second->val){
                temp->next=first;
                temp=first;
                first=first->next;
            }
            else{
                temp->next=second;
                temp=second;
                second=second->next;
            }
        }
        if(first!=NULL){
            temp->next=first;
        }
        if(second!=NULL){
            temp->next=second;
        }
        return dummy->next;
    }
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* mid=getMid(head);
        ListNode* first=head;
        ListNode* second=mid->next;
        mid->next=NULL;
        first=sortList(first);
        second=sortList(second);
        
       ListNode*ans= merge(first,second);
        return ans;
    }
};
