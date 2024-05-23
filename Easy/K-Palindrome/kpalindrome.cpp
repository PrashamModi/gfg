//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int LCS(string &str,string &S,int i,int j,vector<vector<int>>&dp){
    
    if(i>=str.length() || j>=S.length())
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans=0;
    
    if(str[i]==S[j])
    ans=max(ans,1+LCS(str,S,i+1,j+1,dp));
    else{
        ans=max(ans,LCS(str,S,i+1,j,dp));
        ans=max(ans,LCS(str,S,i,j+1,dp));
    }
    return dp[i][j]=ans;
}
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for (int gap = 1; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int v = dp[0][n-1];
        return v <= k;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends