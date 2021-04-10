#include<iostream>
#include<stack>
using namespace std;

class queue{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int x){
        s1.push(x);
    }
    // pop using two stack s1 & s2
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue overflow\n";
            return -1;
        }
        if(s2.empty()){ 
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
       }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    // pop using recursion & one stack s1 
    int pop(){
        if(s1.empty()){
            cout<<"Queue overflow\n";
            return -1;
        }
        int x  = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;

    }

};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    return 0;
}