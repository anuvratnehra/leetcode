//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int backtrack(int arr[], int n, int idx, int sum, int sumhalf1,int sumhalf2){
        if(sumhalf1==sumhalf2 and idx==n) return 1;
        if(sumhalf1>sum/2 or sumhalf2>sum/2) return 0;
        if(backtrack(arr,n,idx+1,sum,sumhalf1+arr[idx],sumhalf2)) return 1;
        if(backtrack(arr,n,idx+1,sum,sumhalf1,sumhalf2+arr[idx])) return 1;
        return 0;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2==1) return 0;
        return backtrack(arr, N, 0, sum,0,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends