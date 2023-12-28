//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool f(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 || j < 0) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp);
        }
        else {
            if(s[i] == '*') {
                return dp[i][j] = f(i, j - 1, s, t, dp) || f(i - 1, j - 1, s, t, dp);
            } else if(s[i] == '?') {
                return dp[i][j] = f(i - 1, j - 1, s, t, dp);
            }
            else return dp[i][j] = false;
        }
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, wild, pattern, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends