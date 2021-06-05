#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    sort(v.begin(),v.end());
    long long mn=0, mx=0;
    for(int i=0; i<n/2; i++){
        mn += (v[2*i+1]-v[2*i]);
        mx += (v[i+n/2]-v[i]);
    }
    cout<<"minimum: "<<mn<<" maximum: "<<mx;
    return 0;
}