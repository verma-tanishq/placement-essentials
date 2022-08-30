// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{   
    bool knows(vector<vector<int> >& M, int n, int a, int b){
        if(M[a][b]==1){
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        int a,b;
        
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size()>1){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            if(knows(M,n,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int top = s.top();
        int rowCount = 0;
        int colCount = 0;
        for(int i=0; i<n; i++){
            if(M[top][i]==0){
                rowCount++;
            }
            if(M[i][top]==1){
                colCount++;
            }
        }
        
        if(colCount==n-1 && rowCount==n){
            return top;
        }
        else{
            return -1;
        }
        
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
