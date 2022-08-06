// C++ program to count occurrence of days in a month
#include <bits/stdc++.h>
using namespace std;

// function to find occurrences
void occurrenceDays(int n, string firstday)
{
	// stores days in a week
	string days[] = { "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };

	// Initialize all counts as 4.
	int count[7];
	for (int i = 0; i < 7; i++)
		count[i] = 4;

	// find index of the first day
	int pos;
	for (int i = 0; i < 7; i++) {
		if (firstday == days[i]) {
			pos = i;
			break;
		}
	}

	// number of days whose occurrence will be 5
	int inc = n - 28;

	// mark the occurrence to be 5 of n-28 days
	for (int i = pos; i < pos + inc; i++) {
		if (i > 6)
			count[i % 7] = 5;
		else
			count[i] = 5;
	}

	// print the days
	for (int i = 0; i < 7; i++) {
		cout << days[i] << " " << count[i] << endl;
	}
}

// driver program to test the above function
int main()
{
	int n = 31;
	string firstday = "Tuesday";
	occurrenceDays(n, firstday);
	return 0;
}
