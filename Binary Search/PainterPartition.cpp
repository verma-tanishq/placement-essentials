#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &boards, int k, int mid){
    int painterCount = 1;
    int arrpainter = 0;
    for(int i=0; i<boards.size(); i++){
        if(arrpainter+boards[i]<=mid){
            arrpainter+=boards[i];
        }
        else{
            painterCount++;
            if(painterCount>k || boards[i]>mid){
                return false;
            }
            arrpainter=boards[i];
        }
        if(painterCount>k){
            return false;
        }
    }
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int start = 0;
    int sum = 0;
    for(int i=0; i<boards.size(); i++){
        sum = sum+boards[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(ispossible(boards,k,mid)){
            ans = mid;
            end=mid-1; 
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

int main(){
	int m=2;
	vector<int> boards = {1,2,3,4};
	cout<<findLargestMinDistance(boards,m);
	return 0;
}
