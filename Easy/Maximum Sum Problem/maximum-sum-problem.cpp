//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
        int calcSum(int n, vector<int>&dp)
        {
            if(n == 0)
                return n;
            if(dp[n] != -1)
                return dp[n];
            int ans = calcSum(n/2, dp) + calcSum(n/3, dp) + calcSum(n/4, dp);
            return dp[n] = max(n ,ans);
        }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n + 1, -1);
            return calcSum(n, dp);
        }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends