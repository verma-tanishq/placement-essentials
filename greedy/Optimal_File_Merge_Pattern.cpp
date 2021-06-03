#include<bits/stdc++.h>
using namespace std;

int minComputation(int n, int files[]){
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i=0; i<n; i++){
        minheap.push(files[i]);
    }
    int count=0;
    while(minheap.size()>1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        int temp = e1+e2;
        count+=temp;
        minheap.push(temp);
    }
    return count;
}

int main()
{
      
    // No of files
    int n = 6;
      
    // 6 files with their sizes
    int files[] = { 2, 3, 4, 5, 6, 7 };
      
    // Total no of computations
    // do be done final answer
    cout << "Minimum Computations = "
         << minComputation(n, files);
  
    return 0;
}