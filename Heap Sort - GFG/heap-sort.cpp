//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int lowest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n and arr[l]<arr[lowest]) lowest =l;
        if(r<n and arr[r]<arr[lowest]) lowest =r;
        if(lowest!=i){
            swap(arr[i],arr[lowest]);
            heapify(arr,n,lowest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    {
        
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
        reverse(arr,arr+n);
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends