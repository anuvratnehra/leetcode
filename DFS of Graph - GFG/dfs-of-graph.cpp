//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,int> visited;
        stack<int>s;
        vector<int>ans;
        s.push(0);
        int curr;
        for(int i=0;i<V;i++){
            reverse(adj[i].begin(),adj[i].end());
        }
        while(!s.empty()){
            curr=s.top();
            s.pop();
            if(visited.find(curr)!=visited.end()) continue;
            else visited[curr]++;
            for(auto i:adj[curr]) s.push(i);
            ans.push_back(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends