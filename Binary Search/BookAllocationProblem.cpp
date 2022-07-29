#include <bits/stdc++.h>
using namespace std;

bool ispossible(int arr[], int mid, int size, int student){
	int students = 1;
	int arrsum = 0;
	for(int i=0; i<size; i++){
		if(arrsum+arr[i]<=mid){
			arrsum+=arr[i];
		}
		else{
			students++;
			if(students>student || arr[i]>mid){
				return false;
			}
			arrsum = arr[i];
		}
	}
	if(students>student){
		return false;
	}
	return true;
}

int bookAllocation(int arr[], int m, int size){
	int start = 0;
	int sum = 0;
	for(int i=0; i<size; i++){
		sum = sum+arr[i];
	}
	int end = sum;
	int mid = start + (end-start)/2;
	int ans = -1;
	while(start<=end){
		if(ispossible(arr,mid,size,m)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}
	return ans;
}

int main(){
	int m=4;
	int arr[4] = {5, 17, 100, 11};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<bookAllocation(arr,m,size);
	return 0;
}
