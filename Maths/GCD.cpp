// C++ program to find GCD of two numbers
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
	// Everything divides 0
	if (a == 0)
	return b;
	if (b == 0)
	return a;

	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a-b, b);
	return gcd(a, b-a);
}

// Driver program to test above function
int main()
{
	int a = 98, b = 56;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
	return 0;
}


// C++ program to find GCD of two numbers
#include <iostream>
using namespace std;
// Function to return gcd of a and b
int gcd(int a, int b)
{
	int result = min(a, b); // Find Minimum of a nd b
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result; // return gcd of a nd b
}

// Driver program to test above function
int main()
{
	int a = 98, b = 56;
	cout << "GCD of " << a << " and " << b << " is "
		<< gcd(a, b);
	return 0;
}
Time Complexity  = O(min(a,b))
  
// C++ program to find GCD of two numbers
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b in single line
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

// Driver program to test above function
int main()
{
	int a = 98, b = 56;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
	return 0;
}
Time Complexity = O(log(min(a,b))
