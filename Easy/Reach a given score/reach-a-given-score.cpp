//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long int f(long long int num, vector<int> &dp) {
        if(num < 0) return 0;
        if(num == 0) return 1;
        if(dp[num] != -1) return dp[num];
        long long int ans = 0;
        ans += f(num - 3, dp);
        ans += f(num - 5, dp);
        ans += f(num - 10, dp);
        return dp[num] = ans;
    }
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	long long int remaining = 0, cnt = 0;
        for(int i=0;i<=(n/3);i++) {
            remaining = n - i*3;
            if(remaining % 5 != 0) continue;
            cnt += (remaining/10) + 1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends