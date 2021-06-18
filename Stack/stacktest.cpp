// #include <bits/stdc++.h>
// using namespace std;
// #define n  10

// class MyStack{
//     int* arr;
//     int minelem;
//     stack<int> s;
//     public:
//     void push(int x){
//         if(s.size()==s.empty()){
//             minelem = x;
//             s.push(x);
//             return;
//         }
//         else if(s.size()==n){
//             cout<<"Stack Overflow";
//             return;
//         }
//         else if(x >= minelem){
//             s.push(x);
//         }
//         else if(x <=minelem){
//             minelem=x;
//             s.push(2*x-minelem);
//         }
//     }

//     int getMin(){
//         if(s.empty()){
//             return -1;
//         }
//         return minelem;
//     }

//     void pop(){
//         if(s.empty()){
//             cout<<"Stack Underflow";
//             return;
//         }
//         int t = s.top();
//         s.pop();

//         if(t<minelem){
//             cout<<minelem<<endl;
//             minelem = 2*minelem-t;
//             return;
//         }
//         else{
//             cout<<t<<endl;
//         }
//     }
//     void peek()
//     {
//         if (s.empty())
//         {
//             cout << "Stack is empty ";
//             return;
//         }
 
//         int t = s.top(); // Top element.
 
//         cout << "Top Most Element is: ";
 
//         // If t < minEle means minEle stores
//         // value of t.
//         (t < minelem)? cout << minelem: cout << t;
//     }

// };


// int main()
// {
//     MyStack s;
//     s.push(3);
//     s.push(5);
//     s.getMin();
//     s.push(2);
//     s.push(1);
//     s.getMin();
//     s.pop();
//     s.getMin();
//     s.pop();
//     s.peek();
 
//     return 0;
// }





// /*

// stack<int> s;
// int minelem;
// void getmin(){
//     if(s.top==-1){
//         return -1;
//     }
//     return minelem;
// }

// void push(int x){
//     if(s.size()==n){
//         cout<<"StackOverflow";
//         return;
//     }
//     else if(s.size()==s.empty()){
//         minelem = x;
//         s.push(x);
//         return;
//     }
//     else if(x=>minelem && !s.empty()){
//         s.push(x);
//     }
//     else if(x<minelem && !s.empty()){
//         minelem = x;
//         s.push(2*x-1);
//     }
// }

// void pop(){
//     int t=s.top();
//     s.pop();

//     if(t<minelem){
        
//         minelem = 2*minelem-t;
//     }
// }

// ---------- 2 stack ----------------


// */

#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str){
    int n = str.length();
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(str[i]=='('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            if(!st.empty()){
                    ans = max(ans, i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    string str = "((()()";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    str = "()(()))))";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    return 0;
}

// <------------------- another approach ------------------>
// C++ program to implement the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the length of
// the longest valid substring
int solve(string s, int n)
{

	// Variables for left and right counter.
	// maxlength to store the maximum length found so far
	int left = 0, right = 0, maxlength = 0;

	// Iterating the string from left to right
	for (int i = 0; i < n; i++)
	{
		// If "(" is encountered,
		// then left counter is incremented
		// else right counter is incremented
		if (s[i] == '(')
			left++;
		else
			right++;

		// Whenever left is equal to right, it signifies
		// that the subsequence is valid and
		if (left == right)
			maxlength = max(maxlength, 2 * right);

		// Reseting the counters when the subsequence
		// becomes invalid
		else if (right > left)
			left = right = 0;
	}

	left = right = 0;

	// Iterating the string from right to left
	for (int i = n - 1; i >= 0; i--) {

		// If "(" is encountered,
		// then left counter is incremented
		// else right counter is incremented
		if (s[i] == '(')
			left++;
		else
			right++;

		// Whenever left is equal to right, it signifies
		// that the subsequence is valid and
		if (left == right)
			maxlength = max(maxlength, 2 * left);

		// Reseting the counters when the subsequence
		// becomes invalid
		else if (left > right)
			left = right = 0;
	}
	return maxlength;
}

// Driver code
int main()
{

	// Function call
	cout << solve("((()()()()(((())", 16);
	return 0;
}
