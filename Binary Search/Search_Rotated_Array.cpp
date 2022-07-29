#include <bits/stdc++.h>
using namespace std;

int getpivot(int arr[], int size){
	int start = 0;
	int end = size-1;
	int mid = start + (end-start)/2;

	while(start<end){
		if(arr[mid]>=arr[0]){
			start = mid+1;
		}
		else {
			end=mid;
		}
		mid = start + (end-start)/2;
	}
	return start;
}

int binarySearch(int arr[], int s, int e, int key){
	int start = s;
	int end = e;
	int mid  = start + (end-start)/2;

	while(start<=end){
		if(key==arr[mid]){
			return mid;
		}
		else if(key>arr[mid]){
			start = mid+1;
		}
		else if(key<arr[mid]){
			end = mid-1;
		}
		mid = start + (end-start)/2;
	}
	return -1;
}

int getkey(int arr[], int size, int key){
	int pivot = getpivot(arr,size);
	if(key>=arr[pivot] && key<=arr[size-1]){
		return binarySearch(arr,pivot,size-1,key);
	}
	else{
		return binarySearch(arr,0,pivot-1,key);
	}
}

int main(){
	int arr[5] = {12, 15, 18, 2, 4};
	int size  = sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter the number to search: "<<endl;
	int k;
	cin>>k;
	cout<<getkey(arr,size,k);
	return 0;
}
