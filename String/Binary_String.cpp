#include<iostream>
using namespace std;

int maxString(string s, int n){
    int count0=0, count1=0;
    int count=0;

    if(n==0 || n==1){
        return -1;
    }

    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            count0++;
        }
        else if(s[i]=='1'){
            count1++;
        }
        if(count0==count1){
            count++;
        }
    }
    if(count0!=count1){
        return -1;
    }
    return count;
}

int main(){
    string str = "0100110101";
    int n = str.length();
    cout<<maxString(str,n);
    return 0;
}
