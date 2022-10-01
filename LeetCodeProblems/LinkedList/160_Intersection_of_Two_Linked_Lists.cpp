/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            if(a==NULL){
                a=headB;
            }
            else{
                a=a->next;
            }
            if(b==NULL){
                b=headA;
            }
            else{
                b=b->next;
            }
        }
        return a;
        // return b;
    }
};


// another approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        if(lenB>lenA){
            int len=lenB-lenA;
            while(len--){
                b=b->next;
            }
                
        }
         if(lenA>lenB){
            int len=lenA-lenB;
            while(len--){
                a=a->next;
            }
                
        }
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return a;
    }
};
