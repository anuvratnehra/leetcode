//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        if(A==B) return 0;
        if(A.length()!=B.length()) return -1;
        vector<int> count(256,0);
        int n= A.length();
        for (int i = 0; i < n; i++)
            count[A[i]]++;
        // subtract count for every character in B
        for (int i = 0; i < n; i++)
            count[B[i]]--;
        // Check if all counts become 0
        for (int i = 0; i < 256; i++)
            if (count[i])
                return -1;
        int i=n-1;
        int j=n-1;
        int result=0;
        while(i>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else{
                while(i>=0 and A[i]!=B[j]){
                    i--;
                    result++;
                }
                i--;
                j--;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends