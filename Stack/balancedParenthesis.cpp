#include<bits/stdc++.h>
using namespace std;

// bool isValid(string str){
//     stack<char> st;
//     bool ans=true;
//     for(int i=0; i<str.length(); i++){
//         if(str[i]=='{' or str[i]=='[' or str[i]=='('){
//             st.push(str[i]);
//         }
//         else if(!st.empty() and str[i]=='}'){
//             if(st.top()=='{'){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//         else if(!st.empty() and str[i]==']'){
//             if(st.top()=='['){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//         else if(!st.empty() and str[i]==')'){
//             if(st.top()=='('){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//     }
//     if(!st.empty()){
//         return false;
//     }
//     return ans;
// }
class Solution
{
    public:
    //Function to check if opening and closing brackets are of same type.
    bool cmp(char b,char c)
    {
        if(b=='{' && c=='}')
            return true;
        else if(b=='[' && c==']')
            return true;
        else if(b=='(' && c==')')
            return true;
         return false;
    }
    
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        
        //iterating over the string.
        for(int i=0;i<x.size();i++)
        {
            //if opening bracket is encountered, we push it into stack.
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
                s.push(x[i]);
            
            //if closing bracket is encountered, we compare it with top of stack.
            else if(x[i]==']' || x[i]=='}' || x[i]==')')
            {
                //if top of stack has opening bracket of different
                //type, we return false.
                if(s.empty() || !cmp(s.top(),x[i])) 
                    return false;
                //else we pop the top element from stack.
                else
                    s.pop();
            }
        }
        //if stack becomes empty, we return true else false.
        if(s.empty())
            return true;
        else
            return false;
    }
};

int main(){
    if(ispar("{[()]}")){
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}
