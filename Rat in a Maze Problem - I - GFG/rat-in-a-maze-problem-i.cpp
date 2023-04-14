//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> answer;
    bool isSafe(vector<vector<int>> m,int x,int y, int n){
        if(x>=0 and y>=0 and x<n and y<n and m[x][y]==1) return true;
        return false;
    }
    void ratInMaze(vector<vector<int>> m, int x, int y, int n, string s){
        if(isSafe(m,x,y,n)){
            if(x==n-1 and y==n-1){
                answer.push_back(s);
                return;
            }
            m[x][y]=0;
            ratInMaze(m,x+1,y,n,s+"D");
            ratInMaze(m,x,y-1,n,s+"L");
            ratInMaze(m,x,y+1,n,s+"R");
            ratInMaze(m,x-1,y,n,s+"U");
        }
        return;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        ratInMaze(m,0,0,n,s);
        return answer;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends