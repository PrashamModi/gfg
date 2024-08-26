//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 && j < 0)return true;
        if(j < 0)return false;
        if(i < 0){
            for(int ind = 0; ind <= j; ind++){
                if(t[ind] != '*')return false;
            }
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j] || t[j] == '?'){
            return dp[i][j] = f(i - 1, j - 1, s, t, dp);
        }
        if(t[j] == '*'){
            return dp[i][j] = f(i, j - 1, s, t, dp) || f(i - 1, j, s, t, dp);
        }
        return dp[i][j] = false;
    }
    int wildCard(string pat, string str) {
        
        int n = str.size();
        int m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, str, pat, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends