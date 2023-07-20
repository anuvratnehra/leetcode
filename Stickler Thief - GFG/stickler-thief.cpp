//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int f(int ind, int n, int arr[], vector<int>&dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int first=f(ind-1,n,arr,dp);
        int second=arr[ind]+f(ind-2,n,arr,dp);
        return dp[ind]=max(first,second);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+1,-1);
        return f(n-1, n ,arr,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends