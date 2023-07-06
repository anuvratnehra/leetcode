//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minNum(int i, int j, string s, string t,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return minNum(i-1,j-1,s,t,dp);
        else{
            int ins=1+minNum(i,j-1,s,t,dp);
            int del=1+minNum(i-1,j,s,t,dp);
            int sub=1+minNum(i-1,j-1,s,t,dp);
            return dp[i][j]=min(sub,min(del,ins));
        }
    }
    int editDistance(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return minNum(s.length()-1,t.length()-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends