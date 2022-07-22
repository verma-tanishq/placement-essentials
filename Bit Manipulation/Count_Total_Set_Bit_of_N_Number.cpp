//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int answer(int n)
    {
        if(n==0)
            return 0;
            
        int i;
        for(i=0;;++i)
        {
            if(pow(2,i)>n)
               break;
        }
        
        int p=i-1;
        
        return pow(2,p-1)*p + (n-pow(2,p)+1) + answer(n-pow(2,p)); 
    }
    int countSetBits(int n)
    {
       return answer(n);        
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
