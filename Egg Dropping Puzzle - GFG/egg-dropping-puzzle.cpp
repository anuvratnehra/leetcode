//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int f(int eggsLeft, int floorNumber, int n,vector<vector<int>>&dp){
        if(floorNumber==0 or floorNumber==1 or eggsLeft==1) return floorNumber;
        if(dp[eggsLeft][floorNumber]!=-1) return dp[eggsLeft][floorNumber];
        int ans=INT_MAX;
        for(int i=1 ;i<=floorNumber;i++){
            int temp=1+max(f(eggsLeft-1,i-1,n,dp),f(eggsLeft,floorNumber-i,n,dp));
            ans=min(ans,temp);
        }
        return dp[eggsLeft][floorNumber]=ans;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n,k,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends