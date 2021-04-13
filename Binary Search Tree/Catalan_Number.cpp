#include<iostream>
using namespace std;

int catalanNumber(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0; i<n; i++){
        res+= catalanNumber(i)*catalanNumber(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0; i<10; i++){
        cout<<catalanNumber(i)<<" ";
    }
    cout<<endl;
    return 0;
}

/*
Time complexity of above implementation is equivalent to nth catalan number. 

The value of nth catalan number is exponential that makes the time complexity exponential.
*/
<------------------------------------------------------------------------------------------------------------>
#include <iostream>
using namespace std;

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n + 1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j] * catalan[i - j - 1];
	}

	// Return last entry
	return catalan[n];
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalanDP(i) << " ";
	return 0;
}

// O(n^2)
