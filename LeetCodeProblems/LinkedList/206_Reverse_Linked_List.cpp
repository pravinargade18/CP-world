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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){    //if there is only one element is present or two elements are present 
            return head;
        }
        ListNode* prev=NULL;             //created prev which is pointing to null 
        ListNode* forward=NULL;         //made forward to keep contact with remaining list
        ListNode* curr=head;            //
        while(curr!=NULL){
            forward=curr->next;  //forward to next
            curr->next=prev;          //curr->next back to prev
            prev=curr;                  //point prev to curr
            curr=forward;               //curr to forward
        }
        return prev;   //return prev as new head
         
    }
};
