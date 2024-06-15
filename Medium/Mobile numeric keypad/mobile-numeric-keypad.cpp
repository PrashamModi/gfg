//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long solve(int n, int x,int y,vector<vector<int >>&matrix,vector<vector<vector<long long >>>&dp){
        if(x< 0 || y < 0 || x==4 || y==3){
            return 0;
        }
        else if(matrix[x][y]==-1){
            return 0;
        }
        else if(dp[n][x][y]!=-1){
            return dp[n][x][y];
        }
        else if(n==0){
            return 1;
        }
        int t = matrix[x][y];
        // cout<<t<<" ";
        long long int self = solve(n-1,x,y,matrix,dp);
        long long int down = solve(n-1,x+1,y,matrix,dp);
        long long int right = solve(n-1,x,y+1,matrix,dp);
        long long int up =solve(n-1,x-1,y,matrix,dp);
        long long int left =solve(n-1,x,y-1,matrix,dp);

        // cout<<down<<" "<<right<<" "<<up <<" "<<left<<" ";
        // cout<<endl;
        return dp[n][x][y] = self + down + right + left + up ;
    }
    long long getCount(int n) {
        if(n==1){
            return 10;
        }
        vector<vector<int>>matrix {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        vector<vector<vector<long long >>>dp(n,vector<vector<long long >>(4,vector<long long >(3,-1)));
        long long ans = 0;
        for(int i = 0 ;i<=9;i++){
            if(i==0){
                ans = ans + solve(n-1,3,1,matrix,dp);
                
            }
            else{
                int y = (i-1)%3;
                int x = (i-1)/3;
                
                ans = ans + solve(n-1,x,y,matrix,dp);
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
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends