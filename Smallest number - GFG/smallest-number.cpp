//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int s, int d){
        string str="";
        int left;
        if(s<1) return "-1";
        if(s-(9*d)>0) return "-1";
        while(d--){
            if(s-1==0 and d>1) str="0"+str;
            else if(s-1==0 and d==0) str="1"+str;
            else if(s-1>=9){
                str="9"+str;
                s-=9;
            } 
            else if(d==0){
                str=to_string(s)+str;
            }
            else{
                str=to_string(s-1)+str;
                s=1;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends