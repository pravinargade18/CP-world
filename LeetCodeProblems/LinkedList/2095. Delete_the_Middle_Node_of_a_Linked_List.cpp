
//Approach 1

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
    int getLength(ListNode *head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int len=getLength(head);
        int middle=len/2;
        int i=1;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(i<middle && curr!=NULL &&  curr->next!=NULL){
            prev=prev->next;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        delete(curr);
        
        return head;
        
    }
};



