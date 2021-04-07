#include<bits/stdc++.h>
using namespace std;

int precedent(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }

    else if(c=='+' || c=='-'){
        return 1;
    }

    else{
        return -1;
    }
}

string infixToPostfix(string str){
    stack<char> st;
    string res;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
            res+=str[i];
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedent(st.top())>precedent(str[i])){
                res+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}

// abc/-ak/l-*

#include<bits/stdc++.h>
using namespace std;

int precendent(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string str){
    stack<char> st;
    string res;
    reverse(str.begin(), str.end());

    for(int i=0; i<str.length(); i++){
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
            res+=str[i];
        }
        else if(str[i]==')'){
            st.push(str[i]);
        }
        else if(str[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else {
            while(!st.empty() && precendent(st.top())>=precendent(str[i])){
                res+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    if(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}

/* Output 
 *-a/bc-/akl
 */
