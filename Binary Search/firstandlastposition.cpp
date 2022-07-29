#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int key, int size){
	int start = 0;
	int end = size-1;
	int mid = start + (end-start)/2;
	int ans = -1;

	while(start<=end){
		if(arr[mid]==key){
			ans = mid;
			end = mid-1;
		}
		else if(key<arr[mid]){
			end = mid-1;
		}
		else if(key>arr[mid]){
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}
	return ans;
}

int lastOcc(int arr[], int key, int size){
	int start = 0;
	int end = size-1;
	int mid = start + (end-start)/2;
	int ans = -1;

	while(start<=end){
		if(arr[mid]==key){
			ans = mid;
			start = mid+1;
		}
		else if(key<arr[mid]){
			end = mid-1;
		}
		else if(key>arr[mid]){
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}
	return ans;
}

int main(){
	int arr[6] = {1,2,2,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int key;
	cout<<"Enter the key to search occurance for: ";
	cin>>key;
	cout<<"First Occurance of element is at Index: "<<firstOcc(arr,key,size)<<endl;
	cout<<"Last Occurance of element is at Index: "<<lastOcc(arr,key,size);
	return 0;
}
