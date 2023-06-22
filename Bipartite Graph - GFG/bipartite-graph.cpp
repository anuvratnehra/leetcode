//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int i, vector<bool>&vis, vector<int>&color, vector<int>adj[]){
        queue<int>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto i:adj[temp]){
                if(color[i]!=-1){
                    if(color[i]!=(color[temp] xor 1)) return false;
                }
                else{
                    color[i]=color[temp] xor 1;
                    if(!vis[i]) q.push(i);
                }
            }
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int>color(n,-1);
	    vector<bool>vis(n,false);
	    color[0]=0;
	    for(int i=0;i<n;i++){
	        if(!vis[i]) if(!bfs(i,vis,color,adj)) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends