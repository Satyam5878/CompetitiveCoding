#include <iostream>
using namespace std;


// Using temporary Array
void shiftElements_UsingTemporaryArray(int arr[],int d,int n){
    int tmpArr[d];
    if(d>=n){
        d=d%n;
    }
    for(int i=0;i<d;++i){
        tmpArr[i] = arr[i];
    }
    for(int i=0,j=d;j<n;++i,++j){
        arr[i] = arr[j];
    }
    for(int i=n-d,j=0;j<d;++i,++j){
        arr[i] = tmpArr[j];
    }

}

void shiftElements_WithoutUsingTmpArr(int arr[],int d,int n){
    if(d>=n){
        d=d%n;
    }
    for(int i=0;i<d;++i){
        int tmp = arr[0];
        for(int j=1;j<n;++j){
            arr[j-1] = arr[j];
        }
        arr[n-1] = tmp;
    }
}


int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
/*
void shiftElements_JugglingAlgorithm(int arr[],int d,int n){
    if(d>=n){
        d=d%n;
    }
    int k = gcd(n,d);
    int tmp;
    int j;
    for(int i=0;i<d;++i){
        tmp = arr[i];
        for(j=i;j+k<n;j=j+k){
            arr[j] = arr[j+k];
        }
        arr[j] = tmp;
    }
}

*/
void shiftElements_JugglingAlgorithm(int arr[],int d,int n){
    int k = gcd(d,n);
    int tmp,j;
    for(int i=0;i<k;++i){
        tmp = arr[i];
        j = i;
        while(1){
           int l = j+d;
           if(l>=n){
               l = l-n;
           }
           if(l == i){
               break;
           }
           arr[j] = arr[l];
           j = l;
        }
        arr[j] = tmp;
    }
}


void printArray(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    //shiftElements_UsingTemporaryArray(arr,2,len);
    //shiftElements_WithoutUsingTmpArr(arr,12,len);
    shiftElements_JugglingAlgorithm(arr,4,len);
    cout<<endl;
    printArray(arr,len);

    return 0;
}
