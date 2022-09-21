//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
private:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* divide(int N, Node *head){
        Node *oddHead=NULL;
        Node* oddTail=oddHead;
        Node *evenHead=NULL;
        Node* evenTail=evenHead;
        
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data%2==0){
                insertAtTail(evenHead,evenTail,temp->data);
            }
            else{
                insertAtTail(oddHead,oddTail,temp->data);
            }
            temp=temp->next;
        }
        if(evenHead==NULL){
            return oddHead;
        }
        
        evenTail->next=oddHead;
        return evenHead;
        
    }
};
