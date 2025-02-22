//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    bool f(int ind, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0){
            return nums[0] == target;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTake = f(ind - 1, nums, target, dp);
        bool take = false;

        if(nums[ind] <= target){ 
            take = f(ind - 1, nums, target - nums[ind], dp);
        }
        return dp[ind][target] = notTake || take;
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int sum = 0;
        for(auto it : arr) sum += it;

        int n = arr.size();
        // for index 'i' is sum 'x' possible or not
        // vector<vector<bool>> dp(n, vector<bool> (totalSum + 1, false));
        
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
	    for(int i = 0; i < n; i++)
	       dp[i][0] = true;
	       
	    if(arr[0] <= sum)dp[0][arr[0]] = true;
	    for(int i = 1; i < n; i++){
	        for(int s = 1; s <= sum; s++){
	            bool nt = dp[i - 1][s];
	            bool tk = false;
	            if(s >= arr[i]){
	                tk = dp[i - 1][s- arr[i]];
	            }
	            dp[i][s] = tk or nt;
	        }
	    }

        // f(n - 1, nums, totalSum, dp);
        // for(int i = 0; i < n; i++) {
        //     for(auto it : dp[i]){
        //         cout<<it<<" -> ";
        //     }
        //     cout<<endl;
        // }

        int ans = INT_MAX;
        for(int currSum = 0; currSum <= sum; currSum++) {
            if(dp[n - 1][currSum] == true){
                int sum1 = currSum, sum2 = sum - currSum;
                ans = min(ans, abs(sum1 - sum2));
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends