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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
     
        ListNode* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        // cout<<prev->val<<endl;
        return prev;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL){
            return head;
        }
        
        ListNode* temp=head;
        ListNode* it= NULL;
        
        while(--left){
            it = temp;
            temp=temp->next;
        }
        
        ListNode* temp1=head;
        while(--right){
            temp1=temp1->next;
        }
        
        // cout<<temp->val<<" "<<temp1->val<<endl;
        
        ListNode* newHead=temp;
        ListNode* forward=temp1->next;
        temp1->next=NULL;
        
        ListNode*mid=reverseList(newHead);
        // cout<<mid->val<<endl;
        
//         // while(mid!=NULL){
//         //     cout<<mid->val<<" ";
//         //     mid=mid->next;
//         // }
        
        if(it == NULL){
            temp->next=forward;
            return mid;
        }
        
        it->next = mid;
        temp->next=forward;
        return head;
        
    }
};
