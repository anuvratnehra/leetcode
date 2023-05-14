//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    bool isValid(vector<int>&sol, int n, int idx){
        if(idx>n) return false;
        for(int i=0;i<idx;i++){
            for(int j=i+1;j<idx;j++){
                if(sol[i]==sol[j] or (sol[i]+(j-i))==sol[j] or (sol[i]-(j-i))==sol[j]) return false;
            }
        }
        return true;
    }
    void backtrack(vector<int>&sol, int n, int idx){
        if(!isValid(sol, n, idx)) return;
        if(idx>=n){
            ans.push_back(sol);
            return;
        }
        // for(auto it:sol) cout<<it<<" ";
        // cout<<endl<<n<<" idx="<<idx<<endl;
        for(int i=1;i<=n;i++){
            sol.push_back(i);
            // for(auto it:sol) cout<<it<<" ";
            // cout<<endl;
            backtrack(sol,n,idx+1);
            sol.pop_back();
        }
        return;
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> sol;
        backtrack(sol,n,0);
        // vector<int>vect={2,4};
        // cout<<isValid(vect,4,2)<<endl;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends