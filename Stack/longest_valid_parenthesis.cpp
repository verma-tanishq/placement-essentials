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
