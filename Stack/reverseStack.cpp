#include<iostream>
#include<stack>
using namespace std;

void reverseStack(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

}

int main(){
    string s = "Hey! I will help you";
    reverseStack(s);
    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
} 

void reverseStack(stack<int> &st){
    if(st.empty()){
        return; 
    }
    int ele=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    return 0;
}