#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string s, char ch[6][6], int size, int idx){
    int found = 0;
    if(i>=0 and j>=0 and i<6 and j<6 and s[idx]==ch[i][j]){
        char temp = s[idx];
        ch[i][j]=0;
        idx+=1;
        if(idx==size){
            found = 1;
        }
        else{
            found+=solve(i+1,j,s,ch,size,idx);
            found+=solve(i-1,j,s,ch,size,idx);
            found+=solve(i,j+1,s,ch,size,idx);
            found+=solve(i,j-1,s,ch,size,idx);
        }
        ch[i][j] = temp;
    }
    return found;
}


int main(){
    string s = "MAGIC";
    char ch[6][6] = { {'B','B','A','B','B','M'},
                       {'C','B','M','B','B','A'},
                       {'I','B','A','B','B','G'},
                       {'G','O','Z','B','B','I'},
                       {'A','B','B','B','B','C'},
                       {'M','C','I','G','A','M'} };
    int ans = 0;
    int size=5;
    for (int i = 0; i <6; i++){
        for(int j=0; j<6; j++){
            ans+=solve(i,j,s,ch,size,0);
        }
    }
 
    cout << "count: " << ans << endl;
                                      
    return 0;
}
