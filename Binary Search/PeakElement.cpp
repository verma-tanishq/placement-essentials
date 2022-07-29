#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[],int size){
	int start = 0;
	int end = size-1;
	int mid = start + (end-start)/2;

	while(start<end){
		if(arr[mid]<arr[mid+1]){
			start = mid+1;
		}
		else{
			end = mid;
		}
		mid = start + (end-start)/2;
	}
	return arr[start];
}

int main(){
	int arr[4] = {3,4,5,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Peak Element is: "<<peakElement(arr,size);
	return 0;
}
