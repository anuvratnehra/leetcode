//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int n, vector<vector<int>> A)
	{
	    vector<int>res;
		for(int i=0;i<n;i++){
		    for(int j=i,k=0;j>=0;j--,k++){
		        res.push_back(A[k][j]);
		    }
		}
		for(int i=1;i<n;i++){
		    for(int j=i,k=n-1;j<n;j++,k--){
		        res.push_back(A[j][k]);
		    }
		}
		return res;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends