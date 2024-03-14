//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        int res = 0;
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        if(a[0][0]=='X') dp[0][0] = {1,1};
        
        for(int i=1; i<n; i++){
            if(a[i][0]=='X'){
                dp[i][0] = {1+dp[i-1][0].first,1};
            }
            if(a[0][i]=='X'){
                dp[0][i] = {1,1+dp[0][i-1].second};
            }
        }
        
        for(int i=1; i<n;i++){
            for(int j=1; j<n; j++){
                if(a[i][j]=='X'){
                    dp[i][j] = {1+dp[i-1][j].first,1+dp[i][j-1].second};
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int mini = min(dp[i][j].first,dp[i][j].second);
                if(mini>res){
                    while(mini>=1 && mini > res){
                        if(dp[i][j-mini+1].first >= mini && dp[i-mini+1][j].second >= mini){
                            res = max(mini,res);
                        }
                        mini--;
                    }
                }
            }
        }
                
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends