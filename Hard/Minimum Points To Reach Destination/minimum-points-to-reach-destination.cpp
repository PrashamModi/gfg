//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int dfs(int i, int j, vector<vector<int>> &points, vector<vector<int>> &dp) {
	    if(i < 0 || i >= points.size() || j < 0 || j >= points[0].size()){
	        return INT_MAX;
	    }
	    if(i == points.size() - 1 && j == points[0].size() - 1) {
	        return points[i][j];
	    }
	    if(dp[i][j] != INT_MIN) return dp[i][j];
	    int down = points[i][j] + dfs(i + 1, j, points, dp);
	    int right = points[i][j] + dfs(i, j + 1, points, dp);
	    
	    down = min(down, 0);
	    right = min(right, 0);
	    
	    return dp[i][j] = max(down, right);
	}
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
	    int val = dfs(0, 0, points, dp);
	    return abs(val) + 1;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends