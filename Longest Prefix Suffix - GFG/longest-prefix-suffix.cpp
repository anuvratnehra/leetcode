//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:
    bool compare(string s, int a, int b){
        int l=s.length();
        for(int i=0;i<=b;i++){
            if(s[i]!=s[a+i]) return false;
        }
        return true;
    }
	int lps(string s) {
	    vector<int>f, l;
	    char first=s[0];
	    char last=s[s.length()-1];
	    for(int i=1;i<s.length()-1;i++){
	        if(s[i]==first) f.push_back(i);
	        if (s[i]==last) l.push_back(i);
	    }
	    reverse(l.begin(),l.end());
	    int i=0,j=0;
	    while(i<f.size() && j<l.size()){
	        if(s.length()-f[i]-1 > l[j]) i++;
	        else if(s.length()-f[i]-1 < l[j]) j++;
	        else{
	            //cout<<"found len"<<" "<<f[i]<<l[j]<<endl;
	            if(compare(s,f[i],l[j])) return s.length()-f[i];
	            i++;
	            j++;
	        }
	    }
	    if(s[0]==s[s.length()-1]) return 1;
	    return 0;
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends