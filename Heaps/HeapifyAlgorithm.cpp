/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

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
    
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
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
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
