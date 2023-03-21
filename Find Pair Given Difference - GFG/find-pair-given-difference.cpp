//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool binarySearch(int arr[], int ele, int l, int r){
    if(ele=arr[l]) return true;
    int mid=(l+r)/2;
    while(l<=r){
        if(ele>=l && ele<=mid) return binarySearch(arr,ele,l,mid);
        else return binarySearch(arr,ele,mid+1,r);
    }
}
bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int i = 0;  
    int j = 1;
 
    while (i<size && j<size)
    {
        if (i != j && arr[j]-arr[i] == n)
        {
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }
 
    return false;
}