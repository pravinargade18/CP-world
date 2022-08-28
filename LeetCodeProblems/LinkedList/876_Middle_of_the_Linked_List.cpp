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
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
     int len=getLength(head);
        int cnt=0;
        int middle=len/2;
        ListNode* temp=head;
        while(cnt<middle){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
};
