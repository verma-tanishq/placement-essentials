// A space optimized solution for
// assembly line scheduling
#include <bits/stdc++.h>
using namespace std;

int carAssembly(int a[][4],
				int t[][4],
				int *e, int *x)
{
	int first, second, i;

	// Time taken to leave first
	// station in line 1
	first = e[0] + a[0][0];
	
	// Time taken to leave first
	// station in line 2
	second = e[1] + a[1][0];

	// Fill tables T1[] and T2[] using the
	// above given recursive relations
	for(i = 1; i < 4; ++i)
	{
		int up = min(first + a[0][i], second + t[1][i] + a[0][i]);
		int down = min(second + a[1][i], first + t[0][i] + a[1][i]);
		first = up;
		second = down;
	}

	// Consider exit times and
	// return minimum
	return min(first + x[0],
			second + x[1]);
}

// Driver Code
int main()
{
	int a[][4] = { { 4, 5, 3, 2 },
				{ 2, 10, 1, 4 } };
	int t[][4] = { { 0, 7, 4, 5 },
				{ 0, 9, 2, 8 } };
	int e[] = { 10, 12 }, x[] = { 18, 7 };

	cout << carAssembly(a, t, e, x);

	return 0;
}

