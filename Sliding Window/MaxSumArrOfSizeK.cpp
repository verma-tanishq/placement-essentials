// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long sum = 0;
        int i=0;
        int j=0;
        long maxi = INT_MIN;
        while(j<N){
            sum = sum+Arr[j];
            if(j-i+1==K){
                maxi = max(maxi,sum);
                sum = sum-Arr[i];
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
