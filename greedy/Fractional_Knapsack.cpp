#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
    Item(int v, int w){
        this->value=v;
        this->weight=w;
    }
};

static bool comp(struct Item a, struct Item b){
    double r1 = (double) a.value/a.weight;
    double r2 = (double) b.value/b.weight;
    return r1>r2;
}

double fractionalKnapsack(int w, struct Item arr[], int n){
    sort(arr,arr+n,comp);
    // int currweight=0;
    // double finalvalue=0.0;
    // for(int i=0; i<n; i++){
    //     if(currweight+arr[i].weight<=w){
    //         currweight+=arr[i].weight;
    //         finalvalue+=arr[i].value;
    //     }
    //     else{
    //         int remain = w-currweight;
    //         finalvalue += arr[i].value*((double) remain)/ (double)arr[i].weight;
    //         break;
    //     }
    int ans=0;
    for(int i=0; i<n; i++){
        if(w>=arr[i].weight){
            ans+=arr[i].value;
            w-=arr[i].weight;
            continue;
        }
        else{
            double vw = (double) arr[i].value/arr[i].weight;
            ans+=vw*w;
            w=0;
        }
    }
    
    return ans;
}

int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}