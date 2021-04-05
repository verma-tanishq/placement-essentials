#include<bits/stdc++.h>
using namespace std;

void duplicateString(string str){
  map<char,int> count;
  for(int i=0; i<str.size(); i++){
    count[str[i]]++;
  }
  for(auto it:count){
    if(it.second>1){
      cout<<it.first<<" "<<it.second<<endl;
    }
  }
}

int main(){
  string s="abafgartba";
  duplicateString(s);
  return 0;
}

/* Output 
a 4
b 2
*/
