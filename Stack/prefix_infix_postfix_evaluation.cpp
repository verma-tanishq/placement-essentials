// #include<iostream>
// #include<math.h>
// #include<stack>
// using namespace std;

// int prefixevaluation(string str){
//     stack <int> st;
//     for(int i=str.length()-1; i>=0; i--){
//         if(str[i]>='0' && str[i]<='9'){
//             st.push(str[i]-'0');
//         }

//         else{
//             int opr1 = st.top();
//             st.pop();
//             int opr2 = st.top();
//             st.pop();

//             switch (str[i])
//             {
//             case '+':
//                 st.push(opr1+opr2);
//                 break;
            
//             case '-':
//                 st.push(opr1-opr2);
//                 break;
            
//             case '*':
//                 st.push(opr1*opr2);
//                 break;
            
//             case '/':
//                 st.push(opr1/opr2);
//                 break;
            
//             case '^':
//                 st.push(pow(opr1,opr2));
//                 break;
//             }
//         }
//     }
//     return st.top();
// }

// int main(){
//     cout<<prefixevaluation("-+7*45+20")<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int postfixEvaluation(string str){
    stack<int> st;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int opr2 = st.top();
            st.pop();

            int opr1 = st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(opr1+opr2);
                break;

            case '-':
                st.push(opr1-opr2);
                break;

            case '*':
                st.push(opr1*opr2);
                break;

            case '/':
                st.push(opr1/opr2);
                break;

            case '^':
                st.push(pow(opr1,opr2));
                break;    
            }
        }
    }
    return st.top();
}

int main(){
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}