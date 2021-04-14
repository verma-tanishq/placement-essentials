#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int clearBit(int n, int pos){
    return (n & (~(1<<pos)));
}

int updateBit(int n, int pos, int val){
    n = (n & (~(1<<pos)));
    return (n | (val<<pos));
}

int isPowerOf2(int n){
    return (n && !(n & n-1));
}

int numberOfOnes(int n){
    int count=0;
    while(n){
        n = (n & n-1);
        count++;
    }
    return count;
}

void subset(int arr[], int n){
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}

int main(){
    cout<<getBit(5,0)<<endl;          // 1
    cout<<setBit(5,1)<<endl;         // 7
    cout<<clearBit(5,2)<<endl;      // 1
    cout<<updateBit(5,1,1)<<endl;  // 7
    cout<<isPowerOf2(16)<<endl;   // 1
    cout<<numberOfOnes(19)<<endl;// 3
    
    int arr[3] = {1,2,3};
    subset(arr,3);
    /* 
    1 
    2
    1 2
    3
    1 3
    2 3
    1 2 3
    */
    return 0;
}