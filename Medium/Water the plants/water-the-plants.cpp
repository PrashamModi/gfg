//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        std::vector<int> dp(n, -1);

    for (int i = 0; i < n; ++i) {
        if (gallery[i] != -1) {
            int left = std::max(0, i - gallery[i]);
            int right = std::min(n - 1, i + gallery[i]);
            for (int j = left; j <= right; ++j) {
                dp[j] = std::max(dp[j], right);
            }
        }
    }

    int count = 0;
    int curr = 0;
    int next = 0;

    while (curr < n) {
        if (dp[curr] == -1) {
            return -1;
        }

        ++count;
        next = dp[curr] + 1;

        if (next >= n) {
            break;
        }

        curr = next;
    }

    return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends