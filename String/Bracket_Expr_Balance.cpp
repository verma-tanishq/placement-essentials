// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;

// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
	int len = expr.length();

	// Expressions of odd lengths
	// cannot be balanced
	if (len % 2 != 0) {
		return -1;
	}
	int left_brace = 0, right_brace = 0;
	int ans;
	for (int i = 0; i < len; i++) {
	
		// If we find a left bracket then we simply
		// increment the left bracket
		if (expr[i] == '{') {
			left_brace++;
		}
	
		// Else if left bracket is 0 then we find
		// unbalanced right bracket and increment
		// right bracket or if the expression
		// is balanced then we decrement left
		else {
			if (left_brace == 0) {
				right_brace++;
			}
			else {
				left_brace--;
			}
		}
	}
	ans = ceil(left_brace / 2) + ceil(right_brace / 2);
	return ans;
}

// Driver program to test above function
int main()
{
	string expr = "}}{{{}";
	cout << countMinReversals(expr);
	return 0;
}
