#include<bits/stdc++.h>
using namespace std;

bool checkStackPermutation(int ip[], int ot[], int n){
    stack<int> st;
    queue<int> input;
    queue<int> output;

    for(int i=0; i<n; i++){
        input.push(ip[i]);
    }

    for(int i=0; i<n; i++){
        output.push(ot[i]);
    }

    while(!input.empty()){
        int ele = input.front();
        input.pop();

        if(ele==output.front()){
            output.pop();
            while(!st.empty()){
                if(st.top()==output.front()){
                    st.pop();
                    output.pop();
                }
                else{
                    break;
                }
            }
        }
        else{
            st.push(ele);
        }
    }
    return (input.empty() && st.empty());
    
}

int main()
{
    // Input Queue
    int input[] = {1, 2, 3};
  
    // Output Queue
    int output[] = {2, 1, 3};
  
    int n = 3;
  
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}