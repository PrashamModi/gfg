//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool f(int ind, int currSum, int n, int coins[], vector<vector<int>> &dp) {
        if(currSum > 0 && (currSum % 20 == 0 || currSum % 24 == 0 || currSum == 2024)) return true;
        if(ind >= n) return false;
        if(dp[ind][currSum] != -1) return dp[ind][currSum];
        bool notTake = f(ind + 1, currSum, n, coins, dp);
        bool take = f(ind + 1, currSum + coins[ind], n, coins, dp);
        return dp[ind][currSum] = take || notTake;
    }
    int isPossible(int n , int coins[])
    {   int sum = 0;
        for(int i = 0; i < n; i++) sum += coins[i];
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(0, 0, n, coins, dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends