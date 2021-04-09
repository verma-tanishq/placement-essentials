
// Simple Approach
#include<bits/stdc++.h>
using namespace std;

unsigned int count(unsigned int n){
    unsigned int Count;
    while(n){
        Count+=n & 1;  //bitwise & it return 1 only if both operands are 1
        n>>=1;
    }
    return Count;
}

int main(){
    cout<<count(9)<<endl;
    return 0;
}


<--------------------------- Recursion Approach ---------------------------------->
  #include <bits/stdc++.h>
using namespace std;

// recursive function to count set bits
int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;

    else

        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}

// driver code
int main()
{
    // get value from user
    int n = 9;

    // function calling
    cout << countSetBits(n);

    return 0;
}


<----------------------- Brian Kernighans Approach ---------------------->
#include <iostream>
using namespace std;
class gfg {
    /* Function to get no of set bits in binary
representation of passed binary no. */
public:
    unsigned int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};
/* Program to test function countSetBits */
int main()
{
    gfg g;
    int i = 9;
    cout << g.countSetBits(i);
    return 0;
}
// O(log n)

