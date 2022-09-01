/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* merge(node* left,node *right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    node* dummy=new node(-1);
    node* ans=dummy;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            ans->next=left;
            ans=left;
            left=left->next;
        }
        else{
            ans->next=right;
            ans=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        ans->next=left;
        ans=left;
        left=left->next;
    }
    while(right!=NULL){
        ans->next=right;
        ans=right;
        right=right->next;
    }
    dummy =dummy->next;
    return dummy;
}
node* findMid(node* head){
    node* fast = head->next;
    node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;    //2 baar aage
    }
    return slow;
}
node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *mid=findMid(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    node* ans=merge(left,right);
    return ans;
    
}
