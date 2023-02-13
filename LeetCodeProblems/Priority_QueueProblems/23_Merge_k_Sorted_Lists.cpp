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
struct compare{  
    public:    
    bool operator()(ListNode* a, ListNode* b){        
        return a->val > b->val;    
    } 
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , compare> pq;        int k = lists.size();    
        if(k==0){        
            return NULL;    
        }        
        for(int i=0;i<k;i++){        
           if(lists[i]!=NULL)            
            pq.push(lists[i]);    
        }        
        ListNode* head = NULL;
        ListNode* tail = NULL;        
        while(!pq.empty()){        
        ListNode* temp = pq.top();                                         
        pq.pop();                
        if(temp->next != NULL){                                                    
            pq.push(temp->next);        
        }                    
        if(head == NULL){                                                           
            head = temp;                                                         
            tail = temp;
        }        
        else{                                                                     
            tail->next = temp;                                                   
            tail = temp;
                                                                                
        }    
                                                                               }    
        return head; 
    }
};
