/* Program to find unique number from array where all number except one is twice */ 
#include<iostream>
using namespace std;

int xorSum(int arr[], int n){
    int xorsum = 0;
    for(int i=0; i<n; i++){
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}

int main(){
    int arr[] = {1,2,3,4,1,4,7,12,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    cout<<xorSum(arr,n);
    return 0;
}
