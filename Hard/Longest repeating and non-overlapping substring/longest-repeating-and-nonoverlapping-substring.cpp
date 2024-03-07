//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
          vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    int res=0,idx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i-1]==s[j-1] && dp[i-1][j-1]<(j-i)){
                
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>res){
                    idx=i;
                    res=dp[i][j];
                }
            }
            else dp[i][j]=0;
        }
    }
        if(res>0){
        string ans;
        for(int i=idx-res;i<idx;i++){
            ans.push_back(s[i]);
        }
        return ans;
        }
     return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends