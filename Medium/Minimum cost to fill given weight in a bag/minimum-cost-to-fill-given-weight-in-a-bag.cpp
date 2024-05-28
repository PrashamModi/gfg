//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    int memo(int ind,int n,int w,vector<int> & cost,vector<vector<int>> &dp){
        if(w==0) return 0;
        if(ind == n) return 1e5+1;
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int res = 1e5+1;
        if(w-ind-1 >= 0){
            res = min(res,memo(ind+1,n,w-ind-1,cost,dp)+cost[ind]);
            res = min(res,memo(ind,n,w-ind-1,cost,dp)+cost[ind]);
        }
        res = min(res,memo(ind+1,n,w,cost,dp));
        return dp[ind][w] = res;
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        return memo(0,n,w,cost,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends