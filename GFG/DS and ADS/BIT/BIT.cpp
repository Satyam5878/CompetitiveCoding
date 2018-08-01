#include<iostream>

using namespace std;

// BIT Data Structure

class BIT{
    public:
        int* freq;int n;
        int* cf;
        int* tree;
        BIT(int f[],int n);   //done
        void buildBIT();      //done
        int query();          
        int getSum();         
        void update(int idx,int value);//done
        void printBIT();      //done

        int get_CF(int idx);
        /**
         * cf(idx)
         * update(idx,val)
         * read_freq(idx)
         * scalingTree(c)
         * findIdx(cf)
         * 
        */
};

BIT::BIT(int f[],int size){
    freq = f;
    n = size;
    tree = new int[size+1];
    for(int i=0;i<=size;++i){
        tree[i] = 0;
    }
    
    buildBIT();
};
void BIT::buildBIT(){
    for(int i=0;i<n;++i){
        update(i+1,freq[i]);
    }
};

void BIT::update(int idx,int value){
    if(idx<1 || idx>n){
        return ;
    }
    while(idx<=n){
        tree[idx] += value;
        idx = idx+ (idx &(-idx));
    }
};

void BIT::printBIT(){
    for(int i=1;i<=n;++i){
        cout<<tree[i]<<" ";
    }
};

int BIT::get_CF(int idx){
    if(idx<1 || idx>n){
        return -1;
    }
    int sum = 0;
    while(idx != 0){
        sum += tree[idx];
        idx = idx - (idx&(-idx));
    }
    return sum;
};
int main(){
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 12;
    BIT* bit = new BIT(freq,n);
    bit->printBIT();
    cout<<"\ncf of 12: "<<bit->get_CF(4);
};