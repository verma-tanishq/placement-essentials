https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1

//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    
    int check(int n){
        int sum=0;
        while(n!=0){
            int r = n%10;
            sum = sum*10+r;
            n = n/10;
        }
        return sum;
    }
    
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0; i<n; i++){
    	    if(check(arr[i])==arr[i]){
    	        continue;
    	    }
    	    esle{
    	        return 0;
    	    }
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
