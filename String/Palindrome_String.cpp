#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string str){
  int i=0;
  int j=str.size()-1;
  while(i<j){
    if(str[i]==str[j]){
      i++;
      j--;
    }
    else{
      return 0;
    }
  }
  return 1;
}

int main(){
  string s = "abbbba";
  cout<<isPalindrome(s)<<endl;
  return 0;
}

/* Output 
1
*/

// CPP program to find if a sentence is
// palindrome
#include <bits/stdc++.h>
using namespace std;

// To check sentence is palindrome or not
bool sentencePalindrome(string str)
{
	int l = 0, h = str.length() - 1;

	// Lowercase string
	for (int i = 0; i <= h; i++)
		str[i] = tolower(str[i]);

	// Compares character until they are equal
	while (l <= h) {

		// If there is another symbol in left
		// of sentence
		if (!(str[l] >= 'a' && str[l] <= 'z'))
			l++;

		// If there is another symbol in right
		// of sentence
		else if (!(str[h] >= 'a' && str[h] <= 'z'))
			h--;

		// If characters are equal
		else if (str[l] == str[h])
			l++, h--;

		// If characters are not equal then
		// sentence is not palindrome
		else
			return false;
	}

	// Returns true if sentence is palindrome
	return true;
}

// Driver program to test sentencePalindrome()
int main()
{
	string str = "Too hot to hoot.";

	if (sentencePalindrome(str))
		cout << "Sentence is palindrome.";
	else
		cout << "Sentence is not palindrome.";

	return 0;
}

// Another approach
// CPP program to find if a sentence is
// palindrome
#include <bits/stdc++.h>
using namespace std;

// To check sentence is palindrome or not
bool isPalindrome(string str)
{
	// Transforming to lowercase
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	// Removing the white-spaces
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	// Creating the copy to string
	string s1 = str;
	string s2 = str;
	// Reversing the string s1
	reverse(s1.begin(), s1.end());
	
	// Evaluating Result
	return s1 == s2;
}

// Driver program to test sentencePalindrome()
int main()
{
	string str = "Too hot to hoot";

	if (isPalindrome(str))
		cout << "Sentence is palindrome.";
	else
		cout << "Sentence is not palindrome.";

	return 0;
}
