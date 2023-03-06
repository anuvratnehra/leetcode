//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(arr[i]);
                arr[i]=-1;
            }
            else if(s.top()<arr[i]){
                int top=s.top();
                s.push(arr[i]);
                arr[i]=top;
            }
            else{
                while(!s.empty() and s.top()>=arr[i]) s.pop();
                if(s.empty()){
                    s.push(arr[i]);
                    arr[i]=-1;
                }
                else{
                    int top=s.top();
                    s.push(arr[i]);
                    arr[i]=top;
                }
            }
        }
        return arr;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends