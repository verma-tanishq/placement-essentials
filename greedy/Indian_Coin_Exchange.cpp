#include <bits/stdc++.h>
using namespace std;

void findMin(int v){
    vector<int> ans;
    int arr[] ={1,2,5,10,20,50,100,500,2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);

    for(int i=n-1; i>=0; i--){
        while(v>=arr[i]){
            v-=arr[i];
            ans.push_back(arr[i]);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}

int main(){
    int v = 11;
    findMin(v);
    return 0;
}