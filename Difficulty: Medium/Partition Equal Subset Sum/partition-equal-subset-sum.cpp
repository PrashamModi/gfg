//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(ind == 0) {
            return arr[0] == target;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target) {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take | notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 2 != 0) return false;
        int target = total / 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends