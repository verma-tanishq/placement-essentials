#include<iostream>
using namespace std;

int main()
{
	cout << " The Pythagorean Triplets less than or equal to 30 are :\n\n";
	
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			for(int k=0;k<30;k++)
			{
				if((i*i)==(j*j)+(k*k) && i!=0 && j!=0 && k!=0)
					cout << "	" << i << "	" << j << "	" << k << "\n";
			}
		}
	}
       return 0;
}
// TC O(n^3)
#include<iostream>
using namespace std;

int main()
{
	int x, y, z = 0;
	
	// loop from 2 to max_limit (here 30)
	int m = 2;

	while (z < 30)
	{
		for (int n = 1; n < m; n++) 
		{
			// Evaluate and print triplets using
			// the relation between a, b and c
			x = m * m - n * n;
			y = 2 * m * n;
			z = m * m + n * n;
			
			if (z > 30)
				break;

			cout<<"\n  "<<x<<" "<<y<<" "<<z;
		}
		m++;
	}
	return 0;
}
// TC O(k) k is number of triplets printed
