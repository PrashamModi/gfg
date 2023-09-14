//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int f(int ind, int arr[], int sum, vector<vector<int>> &dp){
	    if(ind < 0){
	        return sum == 0;
	    }
	    if(dp[ind][sum] != -1){
	        return dp[ind][sum];
	    }
	    int nt = f(ind - 1, arr, sum, dp);
	    int tk = 0;
	    if(arr[ind] <= sum){
	        tk = f(ind - 1, arr, sum - arr[ind], dp);
	    }
	    return dp[ind][sum] =  (nt + tk) % mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, arr, sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends