//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(sum % nums[0] == 0) return sum / nums[0];
            return 1e9;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notTake = f(ind - 1, sum, nums, dp);
        int take = 1e9;
        if(nums[ind] <= sum) {
            take = 1 + f(ind, sum - nums[ind], nums, dp);
        }
        return dp[ind][sum] = min(take, notTake);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int ans = f(n - 1, sum, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends