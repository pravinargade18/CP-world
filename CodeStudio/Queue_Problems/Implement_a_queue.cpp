#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue() {
        // Implement the Constructor
        
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){   //if front and rear are equal then the spaces before them will be empty so we need to point both front and rear at 0th index
                qfront=0;
                rear=0;
            }
            return ans;
            
        }
        
    }

    int front() {
        // Implement the front() function
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
