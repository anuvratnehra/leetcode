//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int n,m;
    vector<vector<int>> distance{{-1,0,1},{-1,0,1}};
    void DFS(vector<vector<char>>& grid,int i, int j){
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j]!='1') return;
        grid[i][j]=-1;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                DFS(grid,i+distance[0][p],j+distance[1][q]);
            }
        }
        return;
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    DFS(grid,i,j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends