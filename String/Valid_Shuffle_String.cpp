//Check if a string is a valid shuffle of two other strings

#include <bits/stdc++.h>
using namespace std;

int shuffleCheck(string s1, string s2, string result){
    if(s1.length()+s2.length()!=result.length()){
        return false;
    }
    int i,j,k=0;
    while(k<result.length()){
        if(i<s1.length() && s1[i]==result[k]){
            i++;
        }
        else if(j<s2.length() && s2[j]==result[k]){
            j++;
        }
        else{
            return false;
        }
        k++;
    }
    if(i<s1.length() || j<s2.length()){
        return false;
    }
    return true;
}

int main(){
    string s1 = "XY";
    string s2 = "12";
    string result = "XY12";

    // call the method to check if result string is
    // shuffle of the string first and second
    
    if (shuffleCheck(s1, s2, result)) {
        cout<<result + " is a valid shuffle of " + s1 + " and " + s2<<endl;
    }
    else {
        cout<<result + " is not a valid shuffle of " + s1 + " and " + s2<<endl;
    }
    return 0;
}
