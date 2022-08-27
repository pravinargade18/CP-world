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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){   //these conditions to check that ll is circular  //if fast at last position and got next as null then no cycle and same for fast->next->next
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){          // there will be definitely one point where fast will be equal to slow if the linked list is circular
                return true;
            }
        }
        return false;
        
    }
};


// Approach 2-using hashmap
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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        unordered_map<ListNode*,bool>visited;
        ListNode* temp=head;
        while(temp!=NULL){
            if(visited[temp]==true){  // if node is already visited
                return true;
            }
            visited[temp]=true; // if not visited then mark true
            temp=temp->next;
            
        }
        return false;
        
    }
};
