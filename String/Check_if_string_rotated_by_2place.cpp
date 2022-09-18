https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string s = str1;
       int n = str1.size();
       
       reverse(str1.begin(), str1.end());
       reverse(str1.begin(), str1.end() - 2);
       reverse(str1.end() - 2, str1.end());
       
       if(str1 == str2) return 1;
       
       
       reverse(s.begin(), s.end());
       reverse(s.begin(), s.begin() + 2);
       reverse(s.begin() + 2, s.end());
       
       if(s == str2) return 1;
       return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends
