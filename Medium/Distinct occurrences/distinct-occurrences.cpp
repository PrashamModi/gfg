//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int mod = 1e9 + 7;
    public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i] == t[j]) {
            return dp[i][j] = (f(i + 1, j + 1, s, t, dp) % mod + f(i + 1, j, s, t, dp) % mod) % mod;
        }
        return dp[i][j] = f(i + 1, j, s, t, dp) % mod;
    }
    
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n = s.length();
      int m = t.length();
      vector<vector<int>> dp(n, vector<int> (m, -1));
      return f(0, 0, s, t, dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends