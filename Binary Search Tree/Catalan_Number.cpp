#include<iostream>
using namespace std;

int catalanNumber(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0; i<n; i++){
        res+= catalanNumber(i)*catalanNumber(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0; i<10; i++){
        cout<<catalanNumber(i)<<" ";
    }
    cout<<endl;
    return 0;
}