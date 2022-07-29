#include <bits/stdc++.h>
using namespace std;

int countPrime(int number){
	vector<bool> prime(number+1,true);
	prime[0] = prime[1]  = false;
	int cnt=0;
	for(int i=2; i<number; i++){
		if(prime[i]){
			cnt++;
			for(int j=2*i; j<number; j=j+i){
				prime[j] = false;
			}
		}
	}
	return cnt;
}

int main(){
	int num;
	cout<<"Enter the number: "<<endl;
	cin>>num;
	cout<<countPrime(num);
	return 0;
}
