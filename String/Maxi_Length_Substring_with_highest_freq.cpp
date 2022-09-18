https://www.geeksforgeeks.org/maximum-length-substring-with-highest-frequency-in-a-string/

// C++ program to find maximum
// occurred substring of a string
#include <bits/stdc++.h>
using namespace std;

// function to return maximum
// occurred substring of a string
string MaxFreq(string str)
{
	// size of the string
	int n = str.size();

	unordered_map<string, int> m;

	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = i; j < n; j++) {
			s += str[j];
			m[s]++;
		}
	}

	// to store maximum frequency
	int maxi = 0;

	// to store string which has maximum frequency
	string s;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second > maxi) {
			maxi = i->second;
			s = i->first;
		}
		else if (i->second == maxi) {
			string ss = i->first;
			if (ss.size() > s.size())
				s = ss;
		}
	}

	// return substring which has maximum frequency
	return s;
}

// Driver program
int main()
{
	string str = "ababecdecd";

	// function call
	cout << MaxFreq(str);

	return 0;
}
