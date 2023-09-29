//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || i == grid.size() || j<0 || j == grid[0].size() || grid[i][j] == 0)
         return;
        grid[i][j] = 0;
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size()-1, n = grid[0].size()-1, ans = 0;
        for(int i=0; i<=m; i++) {
            if(grid[i][0] == 1) dfs(i,0,grid);
            if(grid[i][n] == 1) dfs(i,n,grid);
        }
        for(int j=0; j<=n; j++) {
            if(grid[0][j] == 1) dfs(0,j,grid);
            if(grid[m][j] == 1) dfs(m,j,grid);
        }
        
        for(auto row : grid) {
            for(auto val : row) {
                ans += val;
            }
        }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends