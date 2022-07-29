<------------------------ Binary Search --------------------------->
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){
    int start=0;
    int end=size;
    int mid = start+(end-start)/2;

    while(start<=end){
        if(key>arr[mid]){
            start=mid+1;
        }
        else if(key == arr[mid]){
            return mid;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int main(){
    int EvenArray[5]= {0,3,6,23,145};
    int OddArray[5] = {3,4,5,6,7}; 
    int res = BinarySearch(EvenArray,5,27);
    cout<<"Result is "<<res;
    return 0;
}
Time Complexity O(log n)
Space Complexity O(1)
