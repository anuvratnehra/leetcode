//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int ans=0;
    sort(arr,arr+n);
    ans+=abs(arr[0]-arr[n-1]);
    if(n%2==1){
        for(int i=1;i<=n/2;i++){
            ans+=abs(2*arr[i]-arr[n-i]-arr[n-i-1]);
        }
    }
    else{
        for(int i=1;i<n/2;i++){
            ans+=abs(2*arr[i]-arr[n-i]-arr[n-i-1]);
        }
    }
    ans+=abs(arr[0]-arr[n/2]);
    return ans;
}