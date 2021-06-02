#include<bits/stdc++.h>
using namespace std;

static bool activity(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}

void printMaxActivities(int s[], int f[], int n){
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        v[i] = {s[i],f[i]};
    }
    sort(v.begin(),v.end(),activity);
    int i=0;
    cout<<v[i].first<<" "<<v[i].second;
    cout<<endl;
    for(int j=1; j<n; j++){
        if(v[j].first>=v[i].second){
            cout<<v[j].first<<" "<<v[j].second;
            i=j;
            cout<<endl;
        }
    }
}

int main(){
    int s[] =  {1, 3, 0, 5, 8, 5};  //{{1,2}, {3,4}, {0,6}, {5,7}, {5,9}, {8,9}}
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}