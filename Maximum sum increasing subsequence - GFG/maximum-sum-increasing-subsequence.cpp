//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int helper(int arr[], vector<int>&dp, int n){
	    if(dp[n]!=-1) return dp[n];
	    dp[n]=arr[n];
	    for(int i=0;i<n;i++){
	        if(arr[i]<arr[n])
	        dp[n]=max(dp[n],arr[n]+helper(arr,dp,i));
	    }
	    return dp[n];
	}
	int maxSumIS(int arr[], int n)  
	{  
	    int ans=0;
	    vector<int>dp(n,-1);
	    for(int i=0;i<n;i++){
	        if(dp[i]==-1) helper(arr,dp,i);
	    }
	    for(auto i:dp) {
	       // cout<<i<<endl;
	        ans=max(ans,i);
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends