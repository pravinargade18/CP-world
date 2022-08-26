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


// Recursive solution

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
    void Reverse(ListNode *&head,ListNode* curr,ListNode *prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode* forward=curr->next;   //made link between first node and other nodes
        Reverse(head,forward,curr);
        curr->next=prev;                    
    }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev=NULL;
        ListNode* curr=head;
        Reverse(head,curr,prev);
        return head;
    }
};


// Another recursive solution

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
   ListNode* Reverse(ListNode *&head){
       if(head==NULL || head->next==NULL){     //base case for empty list or single node
           return head;
       }
       
       ListNode* newHead=Reverse(head->next);
       head->next->next=head;
       head->next=NULL;
       return newHead;
   }
public:
    ListNode* reverseList(ListNode* head) {
      return Reverse(head);
    }
};
