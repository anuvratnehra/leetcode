//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    int f(int ind, vector<int>&a, vector<int>&dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int first=f(ind-1,a,dp);
        int second=0;
        if(ind>0) second=a[ind]+a[ind-1]+f(ind-3,a,dp);
        int third=a[ind]+f(ind-2,a,dp);
        return dp[ind]=max(max(first,second),third);
    }
    int findMaxSum(vector<int>& a){
        int n=a.size();
        vector<int>dp(n+1,-1);
        return f(n-1,a,dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends