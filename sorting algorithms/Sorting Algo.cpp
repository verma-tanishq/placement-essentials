<------------------------- Insertion Sort --------------------->

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={5,1,14,2,5};
    int n=5;
    insertionSort(arr, n);
    return 0; 
}

/* Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Insertion
Stable: Yes
*/

<------------------------- Bubble Sort -------------------------------->
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int flag=0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int arr[5] = {23,1,4,4,21};
    int n=5;
    bubbleSort(arr,n);
    return 0;
}

/* Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Exchanging
Stable: Yes
*/

<----------------------------------- Selection Sort ---------------------------------->
#include<iostream>
#include<string>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int temp=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[temp]){
                temp=j;
            }
        }
        if(temp!=i){
            swap(arr[i],arr[temp]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int arr[5] = {12,56,2,1,7};
    int n = 5;
    selectionSort(arr,n);
    return 0;
}
/*
Worst complexity: n^2
Average complexity: n^2
Best complexity: n^2
Space complexity: 1
Method: Selection
Stable: No
*/

<------------------------------ Merge Sort ----------------------------------------->
#include <iostream>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
/*
Inventor: John von Neumann
Worst complexity: n*log(n)
Average complexity: n*log(n)
Best complexity: n*log(n)
Space complexity: n
Method: Merging
Stable: Yes
*/

<--------------------------------- Quick Sort --------------------------------------->
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int loc = partition(arr,lb,ub);
        if(loc==ub){
            partition(arr,lb,loc-1);
        }
        else{
            partition(arr,lb,loc-1);    
            partition(arr,loc+1,ub);
        }
    }
}

int main(){
    int arr[] = {12,3,1,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
/*
Inventor: Tony Hoare
Worst complexity: n^2
Average complexity: n*log(n)
Best complexity: n*log(n)
Method: Partitioning
Stable: No
Class: Comparison sort
*/

<------------------------------------ Count Sort ---------------------------------------->
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
    int k = arr[0];
    for(int i=0; i<n; i++){
        k = max(k,arr[i]);
    }
    int count[n] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]]++; 
    }

    for(int i=1; i<=k; i++){
        count[i]+=count[i-1];
    }

    int output[n] = {0};
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {5,3,1,2,4,2,1,3,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
/*
Worst complexity: n+r
Average complexity: n+r
Space complexity: n+r
Stable: Yes
Class: Non-comparison sort
*/

<------------------------------------ Shell Sort --------------------------------------->
#include<bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n){
    int gap;
    for(gap=n/2; gap>=1; gap/=2){
        for(int i=gap; i<n; i++){
            for(int j=i-gap; j>=0; j-=gap){
                if(arr[j+gap]>arr[j]){
                    break;
                }
                else{
                    swap(arr[j+gap], arr[j]);
                }
            }
        }
    }
}

int main(){
    int arr[] = {23,7,15,19,31,29,9,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
/*
Inventor: Donald Shell
Worst complexity: Depends on gap sequence
Average complexity: n*log(n)^2 or n^(3/2)
Best complexity: n
Method: Insertion
Stable: No
Class: Comparison sort
*/

<------------------------------------ Radix Sort using count method ----------------------------------->

#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int pos);

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixSort(int arr[], int n){
    int pos;
    int k = getMax(arr, n);
    for(pos=1; k/pos>0; pos*=10){
        countSort(arr,n,pos);
    }
}

void countSort(int arr[], int n, int pos){
    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[(arr[i]/pos)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i]+=count[i-1];
    }

    int output[n] = {0};
    for(int i=n-1; i>=0; i--){
        output[--count[(arr[i]/pos)%10]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {23,7,15,19,31,29,9,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
/*
Worst complexity: n*k/d
Average complexity: n*k/d
Space complexity: n+2^d
Stable: Yes
Class: Non-comparison sort
*/

<-------------------------------- Bucket Sort ------------------------------------->
#include<bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n){
    vector<float> b[n];
    for(int i=0; i<n; i++){
        int bi = arr[i]*n;
        b[bi].push_back(arr[i]);
    }

    for(int i=0; i<n; i++){
        sort(b[i].begin(), b[i].end());
    }

    int index=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    float arr[] = {0.234, 0.134, 0.2345, 0.12};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}

The average time O(n + k). 
The worst time complexity O(n²). 
The space complexity is O(n+k).

<---------------------------------------- Heap Sort ------------------------------------------>
// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
/*
Inventor: J. W. J. Williams
Worst complexity: n*log(n)
Average complexity: n*log(n)
Best complexity: n*log(n)
Space complexity: 1
Method: Selection
Stable: No
*/

<------------------------------------ Interpolation Sort ------------------------------------>
// C++ program to implement interpolation search
#include<bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int n, int x)
{
	// Find indexes of two corners
	int lo = 0, hi = (n - 1);

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x) return lo;
			return -1;
		}
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo])) * (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in upper part
		if (arr[pos] < x)
			lo = pos + 1;

		// If x is smaller, x is in the lower part
		else
			hi = pos - 1;
	}
	return -1;
}

// Driver Code
int main()
{
	// Array of items on which search will
	// be conducted.
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
				22, 23, 24, 33, 35, 42, 47};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x = 18; // Element to be searched
	int index = interpolationSearch(arr, n, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}

Lets assume that the elements of the array are linearly distributed. 

General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])

Class	Sorting Algorithm
Data structure	Array
Worst-case performance	 O(n^(2))
Best-case performance	 O(n)
Average performance	 O(n+k)
Worst-case space complexity O(n*3)

<------------------------------------ 3 way Quick Sort (Dutch National Flag) ---------------------------------->
// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {
		// From left, find the first element greater than
		// or equal to v. This loop will definitely
		// terminate as v is last element
		while (a[++i] < v)
			;

		// From right, find the first element smaller than
		// or equal to v
		while (v < a[--j])
			if (j == l)
				break;

		// If i and j cross, then we are done
		if (i >= j)
			break;

		// Swap, so that smaller goes on left greater goes
		// on right
		swap(a[i], a[j]);

		// Move all same left occurrence of pivot to
		// beginning of array and keep count using p
		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}

		// Move all same right occurrence of pivot to end of
		// array and keep count using q
		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}

	// Move pivot element to its correct index
	swap(a[i], a[r]);

	// Move all left same occurrences from beginning
	// to adjacent to arr[i]
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);

	// Move all right same occurrences from end
	// to adjacent to arr[i]
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	// Note that i and j are passed as reference
	partition(a, l, r, i, j);

	// Recur
	quicksort(a, l, j);
	quicksort(a, i, r);
}

// A utility function to print an array
void printarr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

// Driver code
int main()
{
	int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
	int size = sizeof(a) / sizeof(int);

	// Function Call
	printarr(a, size);
	quicksort(a, 0, size - 1);
	printarr(a, size);
	return 0;
}
