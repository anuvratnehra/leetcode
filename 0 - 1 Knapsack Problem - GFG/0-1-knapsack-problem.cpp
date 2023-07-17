//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSack(int w, int wt[], int val[], int n) 
    {
        vector<int>dp(w+1,0);
        //vector<vector<int>>dp(n,vector<int>(w+1,0));
        for(int i=wt[0];i<=w;i++){
            dp[i]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int weight=w;weight>=0;weight--){
                int take=INT_MIN;
                if(wt[i]<=weight) take=val[i]+dp[weight-wt[i]];
                int notTake=dp[weight];
                dp[weight]=max(take,notTake);
            }
        }
        return dp[w];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends