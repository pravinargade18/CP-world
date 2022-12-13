#include <bits/stdc++.h>

using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        size=0;
        arr[0]=-1;
    }
    
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    
    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to delete in heap"<<endl;
            return;
        }
        
        arr[1]=arr[size];
        size--;
        
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            
            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            
            else{
                return;
            }
        }
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
    }
    
};

void heapify(int arr[],int size,int i){
    int largest=i;
    int left=2*i;
    int right= 2*i +1;
    
    if(left<=size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=size && arr[right]>arr[largest]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
    
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
    
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
    
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    
    cout<<"printing the array after heapify:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //heap sort
    heapSort(arr,n);
    cout<<"printing the array after Heap sort:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //implementation of heap using priority queue
    // in priority queue heap is maxHeap by default  
    priority_queue<int>pq;
    pq.push(9);
    pq.push(7);
    pq.push(12);
    pq.push(5);
    pq.push(4);
    
    cout<<"Top:"<<pq.top()<<endl;//12
    pq.pop();
    
    cout<<"Top:"<<pq.top()<<endl;//9
    
    cout<<"size "<<pq.size()<<endl; //4
    
    cout<<"Empty "<<pq.empty()<<endl; //0 false
    
    //min heap can implemented like below using priority_queue
    
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(9);
    minHeap.push(7);
    minHeap.push(12);
    minHeap.push(5);
    minHeap.push(4);
    
    cout<<"Top:"<<minHeap.top()<<endl;//12
    minHeap.pop();
    
    cout<<"Top:"<<minHeap.top()<<endl;//9
    
    cout<<"size "<<minHeap.size()<<endl; //4
    
    cout<<"Empty "<<minHeap.empty()<<endl; //0 false
    
    
    

    return 0;
}

