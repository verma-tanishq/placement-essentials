#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& c, int n) 
    {
        // code here 
        // int a = 0;
        // int b = n - 1;
        
        // //we keep moving till the a<b. 
        // while (a < b) {
        //     if (M[a][b])
                
        //         a++;
        //     else
        //         b--;
        //     //cout<<M[a][b]<<endl;
        // }
        
        // //checking if a is actually a celebrity or not.
        // for (int i = 0; i < n; i++)
        // {
        //     //if any person doesn't know a or a knows any person, we return -1. 
        //     if ( (i != a) && (M[a][i] || !M[i][a]) )
        //         return -1;
        // }
        // //if we reach here a is celebrity so we retun a.
        // return a;

       stack<int> s;
       //push all the member from 0 to n-1 into the stack
       for(int i=0;i<n;++i)
           s.push(i);
           
       while(s.size()!=1)
       {
           int x=s.top();
           s.pop();
           int y=s.top();
           s.pop();
           
           // if x knows y then x cannot be a celebrity.
           if(c[x][y]==1)
              s.push(y);
              
           // if x doesnt know y then y cannot be celebrity.       
           else
              s.push(x);
       }
       
       // ans variable stores the possible index of celebrity
       int ans=s.top();
       int i,row=ans,col=ans;
       
       //checking the row of the possible answer
       for(i=0;i<n;++i)
          if(c[row][i]==1)
              break;
      // this means that our possble celebrity does not know somebody
      // and hence ans cannot be a celebrity
      if(i!=n)
         return -1;
     
      //checking the column of the possible answer    
       for(i=0;i<n;++i)
           {
               if(i==ans)
                   continue;
                   
               else
                 {
                     if(c[i][col]==0)
                        break;
                 }
           }
        // this means that somebody does not know our possible celebrity
        // and hence ans cannot be a celebrity   
        if(i!=n)
            return -1;
            
      // this means the answer found earlier is the celebrity      
        return ans;    
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>M(n, vector<int>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;
    }
    return 0;
}