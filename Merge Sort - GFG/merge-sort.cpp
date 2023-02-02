//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int leftArraySize=m-l+1, rightArraySize=r-m;
        auto * leftArray = new int[leftArraySize],
             * rightArray=new int[rightArraySize];
        for(int i=0;i<leftArraySize;i++){
            leftArray[i]=arr[l+i];
        }
        for(int i=0;i<rightArraySize;i++){
            rightArray[i]=arr[m+i+1];
        }
        int leftArrayIndex=0,rightArrayIndex=0;
        int arrayIndex=l;
        while(leftArrayIndex<leftArraySize && rightArrayIndex<rightArraySize){
            if(leftArray[leftArrayIndex]<=rightArray[rightArrayIndex]){
                arr[arrayIndex++]=leftArray[leftArrayIndex++];
            }
            else{
                arr[arrayIndex++]=rightArray[rightArrayIndex++];
            }
        }
        while(leftArrayIndex<leftArraySize){
            arr[arrayIndex++]=leftArray[leftArrayIndex++];
        }
        while(rightArrayIndex<rightArraySize){
            arr[arrayIndex++]=rightArray[rightArrayIndex++];
        }
        delete[] leftArray;
        delete[] rightArray;
        return;
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
        return;
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends