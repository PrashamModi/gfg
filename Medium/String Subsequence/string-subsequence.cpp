//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1e9 + 7;
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j >= t.length()) {
            j = 0;
            return 1;
        }
        if(i >= s.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int take = 0;
        if(s[i] == t[j]) {
            take += (f(i + 1, j + 1, s, t, dp) % mod + f(i + 1, j, s, t, dp) % mod) % mod;
        }
        else{
            take += f(i + 1, j, s, t, dp);
        }
        return dp[i][j] = take % mod;
    }
    int countWays(string s, string t) {
        // code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s, t, dp) % mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends