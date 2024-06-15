#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int capacity; //to check if the heap is full or not
    int size;

    Heap(int capacity){
      this->arr= new int[capacity];
      this->capacity= capacity;
      //size= current no of elements in heap
      this->size=0;
    }
    void insert(int val){
        if(size==capacity){
            cout<<"heap overflow"<<endl;
            return;
        }
        //size increase kar jaega
        size++;
        int index= size;
        arr[index]=val;
    
    while(index>1){
       int parentIndex= index/2;
       if(arr[index]>arr[parentIndex]){
        swap(arr[index],arr[parentIndex]);
        index= parentIndex;
       }
       else{
        break;
       }
    }
    }
    void printHeap(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
    }

    int deleteFromHeap(){
        int answer = arr[1];
        //replace
        arr[1]= arr[size];
        size--;

        //heapify'
        int index=1;
        while(index<size){
            int leftIndex= 2*index;
            int rightIndex= 2*index+1;
            //find out karo sabse badha kaun
            int largestIndex = index;
            //check left
            if(leftIndex<=size && arr[largestIndex]<arr[leftIndex]){
                largestIndex= leftIndex;
            }
            if(rightIndex<=size && arr[largestIndex]<arr[rightIndex]){
                largestIndex= rightIndex;
            }
            //no change
            if(index==largestIndex){
                break;
            }  
            else{
                swap(arr[index],arr[largestIndex]);
                index= largestIndex;
            }
        }
        return answer;
    }
};

int main(){
   Heap h(20);
   //insertion
   h.insert(10);
   h.insert(20);
   h.insert(5);
   h.insert(11);
   h.insert(6);
   cout<<"printing the content of heap"<<endl;
   h.printHeap();

   int ans = h.deleteFromHeap();
   cout<<"ans"<<ans<<endl;
    h.printHeap();
}