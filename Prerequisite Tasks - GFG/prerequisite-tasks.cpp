//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    int cnt=0;
	    vector<vector<int>>adj;
	    vector<int>indegree(n,0);
	    for(int i=0;i<n;i++) adj.push_back(vector<int>());
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	        indegree[prerequisites[i].second]++;
	    }
	    queue<int>q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        cnt++;
	        int temp=q.front();
	        q.pop();
	        for(auto i:adj[temp]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    if(cnt==n) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends