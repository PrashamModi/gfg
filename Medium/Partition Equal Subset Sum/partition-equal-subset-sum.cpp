//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int ind, int arr[], int tar, vector<vector<int>> &dp){
        if(tar == 0)return true;
        if(ind == 0){
            return (arr[0] == tar);
        }
        if(dp[ind][tar] != -1)return dp[ind][tar];
        bool nt = f(ind - 1, arr, tar, dp);
        bool tk = false;
        if(tar >= arr[ind]){
            tk = f(ind - 1, arr, tar - arr[ind], dp);
        }
        return dp[ind][tar] = nt | tk;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        long long sum = 0;
        for(int i = 0; i < n; i++)sum += arr[i];
        if(sum % 2 != 0)return false;
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return f(n - 1, arr, sum/2, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends