//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int ind1=0,ind2=0,ind3=0;
        int sum1=0,sum2=0,sum3=0;
        for(auto i:S1) sum1+=i;
        for(auto i:S2) sum2+=i;
        for(auto i:S3) sum3+=i;
        //cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
        int maxSum;
        while(sum1!=sum2 or sum2!=sum3){
            maxSum=max(max(sum1,sum2),sum3);
            if(maxSum==sum1){
                sum1-=S1[ind1++];
            }
            else if(maxSum==sum2){
                sum2-=S2[ind2++];
            }
            else{
                sum3-=S3[ind3++];
            }
            //cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
        }
        return sum1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends