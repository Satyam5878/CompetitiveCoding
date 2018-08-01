#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * Max Heap
 * indexed from 15
 * 
 * */

class MaxHeap{

    public:
    vector<int> heap_arr;

    MaxHeap();
    int heapSize();
    int getMax();
    int getParentIndex(int idx);
    int getLeftChildIndex(int idx);
    int getRightChildIndex(int idx);
    int extractMax();
    void insertElement(int item);
    void decreaseKey();
    void buildHeapUp(int arr[],int len);
    void buildHeapDown(int arr[],int len);
    void restoreUp(int idx);
    void restoreDown(int idx);
    void printHeap();
    
    
    
};

MaxHeap::MaxHeap(){
    heap_arr.push_back(0);
};

int MaxHeap:: heapSize(){
    return heap_arr.size()-1;
}
int MaxHeap::getMax(){
    if(heapSize() > 1){
        return heap_arr[1];
    }
    else{
        return -1;
    }
}
int MaxHeap::getParentIndex(int idx){
    return idx/2;
}
int MaxHeap::getLeftChildIndex(int idx){
    return 2*idx;
}
int MaxHeap::getRightChildIndex(int idx){
    return 2*idx+1;
}

int MaxHeap::extractMax(){
    swap(heap_arr[1],heap_arr[heapSize()]);

    heap_arr.pop_back();

    restoreDown(1);

}

 /** Algorithm: 
  *      Input: takes element to insert
  *       
  *      Procedure:
  *         insert the elememt at the end of the heap arr.
  *         call restoreUp method to put it at its correct place.  
  * 
 */
void MaxHeap::insertElement(int item){
   heap_arr.push_back(item);
   //cout<<"Heap Size: "<<heap_arr.size()<<endl;
   restoreUp(heapSize());//heap_arr.size()-1);
   //printHeap();
   //cout<<endl;
};

void MaxHeap::buildHeapUp(int arr[],int len){
    heap_arr.assign(arr,arr+len);
    heap_arr.insert(heap_arr.begin(),0);
    for(int i=2;i<=heapSize();++i){
        restoreUp(i);
    }
}
void MaxHeap::buildHeapDown(int arr[],int len){
    heap_arr.assign(arr,arr+len);
    heap_arr.insert(heap_arr.begin(),0);
    for(int i=heapSize()/2;i>=1;++i){
        restoreDown(i);
    }
}


/**
 * Algorithm:
*/
void MaxHeap::restoreUp(int idx){
    if(idx == 1){
        return;
    }
    int par_idx = idx/2;
    //cout<<"Par_Idx : "<< par_idx<<" Idx: "<<idx<<endl;
    //cout<<"Par: "<<heap_arr[par_idx]<<" Item: "<<heap_arr[idx]<<endl;
    if(heap_arr[idx] > heap_arr[par_idx]){
        /* int tmp = heap_arr[idx];
        heap_arr[idx] = heap_arr[par_idx];
        heap_arr[par_idx] = tmp;
        //cout<<"tmp : "<<tmp<< " " ;
        cout<<" Heap Element: " <<heap_arr[idx]<<" Tmp: "<<tmp<< endl;
        restoreUp(par_idx); */
        swap(heap_arr[idx],heap_arr[par_idx]);
        restoreUp(par_idx);
    }
};

void MaxHeap::restoreDown(int idx){
    int leftIdx = getLeftChildIndex(idx);
    int rightIdx = getRightChildIndex(idx);
    int childIdx;
    if(leftIdx > heapSize()){
        return;
    }
    else if(rightIdx > heapSize()){
        childIdx = leftIdx;
    }
    else{
        childIdx = heap_arr[leftIdx] >= heap_arr[rightIdx]? leftIdx: rightIdx;
    }

    if(heap_arr[childIdx] > heap_arr[idx]){
        swap(heap_arr[idx],heap_arr[childIdx]);
        restoreDown(childIdx);
    }

    
}
void MaxHeap::printHeap(){
    for(std::vector<int>::iterator itr=heap_arr.begin() ; itr != heap_arr.end() ; ++itr){
        cout<< *itr<< " ";
    }
}

 


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {80,59,45,24,46,37,12,14,10,38};
    MaxHeap maxHeap;
    for(int i=0;i<10;++i){
        maxHeap.insertElement(arr2[i]);
    }

    maxHeap.printHeap();
    /* maxHeap.insertElement(70);
    cout<<endl;
    maxHeap.printHeap(); */

    cout<< endl<<maxHeap.extractMax();
    cout<<endl;
    maxHeap.printHeap();


    int arr3[] = {1,2,3,4,5,6,7,8};
    maxHeap.buildHeapUp(arr3,8);
    cout<<endl;
    maxHeap.printHeap();
    return 0;
};