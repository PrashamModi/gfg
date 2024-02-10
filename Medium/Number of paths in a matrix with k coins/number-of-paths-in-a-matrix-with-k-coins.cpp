//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long dp[101][101][101];
    long long f(int i, int j, int n, int k, vector<vector<int>> &arr) {
        if((i >= n) || (j >= n) || (k < 0)) return 0ll;
        if((i == n - 1) && (j == n - 1) && (k - arr[i][j] == 0)) {
            return 1ll;
        }
        if(dp[k][i][j]!=-1) return dp[k][i][j];
        return dp[k][i][j] = f(i + 1, j, n, k - arr[i][j], arr) + f(i, j + 1, n, k - arr[i][j], arr);
        
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        memset(dp,-1,sizeof(dp));
        return f(0ll, 0ll, n, k, arr);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends