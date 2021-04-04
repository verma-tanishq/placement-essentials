#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack<char> st;
    bool ans=true;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='{' or str[i]=='[' or str[i]=='('){
            st.push(str[i]);
        }
        else if(!st.empty() and str[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!st.empty() and str[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!st.empty() and str[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return ans;
}

int main(){
    if(isValid("{[()]}")){
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}