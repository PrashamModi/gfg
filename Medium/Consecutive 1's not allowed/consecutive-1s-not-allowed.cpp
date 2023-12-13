//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
int mod=1e9+7;
int dp[100005][2];
int fun(int i,int n,int prev){
    if(i==n){
        return 1;
    }
    if(i>n)return 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    int ans=0;
    if(prev!=1){
        ans=(ans+fun(i+1,n,1)%mod+fun(i+1,n,0)%mod)%mod;
    }
    else{
        ans=(ans+fun(i+1,n,0))%mod;
    }
    return dp[i][prev]=ans%mod;
    
}
	// #define ll long long
	ll 	countStrings(int n) {
	   int i=0;
	   memset(dp,-1,sizeof(dp));
	   int prev=0;
	   return fun(i,n,prev)%mod;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends