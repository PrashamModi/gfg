//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp) {
        if(ind == 0) {
            return sum % coins[0] == 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notTake = f(ind - 1, sum, coins, dp);
        int take = 0;
        if(coins[ind] <= sum) {
            take = f(ind, sum - coins[ind], coins, dp);
        }
        return dp[ind][sum] = take + notTake;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends