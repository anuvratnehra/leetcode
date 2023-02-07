//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isHigher(char a, char b){
        if((a=='*' || a== '/') && (b=='+' || b=='-')) return true;
        if((a=='^') && (b=='+' || b=='-')) return true;
        if((a=='^') && (b=='*' || b=='/')) return true;
        if((b=='(')) return true;
        return false;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> stk;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) ans+=s[i];
            else if(s[i]=='(') stk.push('(');
            else if(s[i]==')'){
                while(stk.top()!='('){
                    ans+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else{
                if(stk.empty()) stk.push(s[i]);
                else if(isHigher(s[i],stk.top())) stk.push(s[i]);
                else{
                    while(!stk.empty() && !isHigher(s[i],stk.top())){
                        ans+=stk.top();
                        stk.pop();
                    }
                    stk.push(s[i]);
                }
            }
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends