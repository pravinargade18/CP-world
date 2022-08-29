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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        
        while(temp!=NULL ){
            if( temp->next!=NULL && temp->val==temp->next->val){
                ListNode* nodeToPoint=temp->next->next;    //storing location so that we can keep track 
                ListNode* nodeToDelete=temp->next;
                 delete(nodeToDelete);
                temp->next=nodeToPoint;
               
            }
            else{
                temp=temp->next;
            }
            
        }
        return head;
    }
};
