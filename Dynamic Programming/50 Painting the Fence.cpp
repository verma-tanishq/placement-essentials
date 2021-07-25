// C++ program for Painting Fence Algorithm
// optimised version

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
	long dp[n + 1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;

	dp[1] = k;
	dp[2] = k * k;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}
  /*
  long long same=0, diff=k, total=diff+same;
  for(int i=2; i<=n; i++){
            same = diff;
            diff = total*(k-1);
            diff = diff%mod;
            total = (diff+same)%mod;
        }
  */

	return dp[n];
}

// Driver code
int main()
{
	int n = 3,   //post or fence
	int k = 2;  //color
	cout << countWays(n, k) << endl;
	return 0;
}
