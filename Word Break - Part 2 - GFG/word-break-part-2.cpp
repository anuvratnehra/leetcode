//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>ans;
    bool foundWord(vector<string>&dict,string s){
        for(auto i:dict) if(i==s) return true;
        return false;
    }
    void backtrack(int n, vector<string>&dict, string s,int idx, vector<string> &possible){
        // if(possible.size()>0){
        //     for(auto i:possible) cout<<i<<" ";
        //     cout<<" "<<s<<endl;
        // }
        if(s.length()==0){
            string temp="";
            for(auto i:possible) temp+=i+" ";
            ans.push_back(temp.substr(0,temp.length()-1));
            return;
        }
        if(idx>=s.length()) return;
        if(foundWord(dict,s.substr(0,idx+1))){
            possible.push_back(s.substr(0,idx+1));
            backtrack(n,dict,s.substr(idx+1),0,possible);
            possible.pop_back();
        }
        backtrack(n,dict,s,idx+1,possible);
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> possible;
        backtrack(n,dict,s,0,possible);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends