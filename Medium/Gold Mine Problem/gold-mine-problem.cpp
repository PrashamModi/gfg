//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dx[3] = {-1,0,1};
int dy[3] = {1,1,1};
class Solution{
public:
    bool isValid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    int solve(int i,int j,vector<vector<int>>&M,vector<vector<int>>&dp){
        if(!isValid(i,j,M.size(),M[0].size())){
            return 0;
        }
        int ans=M[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int solv=-1;
        for(int k=0;k<3;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            solv = max(solve(x,y,M,dp),solv);
        }
        return dp[i][j]=ans+solv;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,0,M,dp));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends