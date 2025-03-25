//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
     static bool evaluate(int b1, int b2, char op) {
        if (op == '&')
            return (b1 & b2) == 1;
        if (op == '|')
            return (b1 | b2) == 1;
        return (b1 ^ b2) == 1;
    }
    int countWays(string &s) {
        // code here
        int n = s.length();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>(2, 0)));

        // Initialize base cases for single characters
        for (int i = 0; i < n; i += 2) {
            dp[i][i][1] = (s[i] == 'T') ? 1 : 0;
            dp[i][i][0] = (s[i] == 'F') ? 1 : 0;
        }

        // Fill the DP table for larger substrings
        for (int len = 2; len < n; len += 2) {
            for (int i = 0; i < n - len; i += 2) {
                int j = i + len;
                dp[i][j][0] = dp[i][j][1] = 0;

                for (int k = i + 1; k < j; k += 2) {
                    char op = s[k];
                    int leftTrue = dp[i][k - 1][1],
                        leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1],
                        rightFalse = dp[k + 1][j][0];

                    // Update dp[i][j][1] (True case)
                    if (evaluate(1, 1, op))
                        dp[i][j][1] += leftTrue * rightTrue;
                    if (evaluate(1, 0, op))
                        dp[i][j][1] += leftTrue * rightFalse;
                    if (evaluate(0, 1, op))
                        dp[i][j][1] += leftFalse * rightTrue;
                    if (evaluate(0, 0, op))
                        dp[i][j][1] += leftFalse * rightFalse;

                    // Update dp[i][j][0] (False case)
                    if (!evaluate(1, 1, op))
                        dp[i][j][0] += leftTrue * rightTrue;
                    if (!evaluate(1, 0, op))
                        dp[i][j][0] += leftTrue * rightFalse;
                    if (!evaluate(0, 1, op))
                        dp[i][j][0] += leftFalse * rightTrue;
                    if (!evaluate(0, 0, op))
                        dp[i][j][0] += leftFalse * rightFalse;
                }
            }
        }

        // Return the number of ways to evaluate the entire expression to True
        return dp[0][n - 1][1];

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends