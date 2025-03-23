//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, string s, vector<int> &dp) {
        if(ind == s.length()) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '0') return 0;
        int cnt1 = f(ind + 1, s, dp);
        int cnt2 = 0;
        if(ind < s.size() - 1) {
            if(s[ind] == '1' || (s[ind] == '2' && s[ind + 1] < '7')) {
                cnt2 = f(ind + 2, s, dp);
            }
        }
        return dp[ind] =  cnt1 + cnt2;
    }
    int countWays(string &s) {
        // Code here
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return f(0, s, dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends