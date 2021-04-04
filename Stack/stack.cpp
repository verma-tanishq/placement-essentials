#include<iostream>
using namespace std;

#define n 100

class Stack{
    int* arr;
    int top;
    public:
        Stack(){
            arr = new int[n];
            top = -1;
        }

        void pop(){
            if(top==-1){
                cout<<"No element to pop";
                return;
            }
            top--;
        }

        void push(int x){
            if (top==n-1){
                cout<<"Stack Overflow";
                return;
            }
            top++;
            arr[top] = x;
        }

        int Top(){
            if(top==-1){
                cout<<"No element in stack \n";
                return -1;
            }
            return arr[top];
        }

        bool empty(){
            return top==-1;
        }
};

int main(){
    Stack st;
    st.push(12);
    st.push(24);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<'\n'<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}