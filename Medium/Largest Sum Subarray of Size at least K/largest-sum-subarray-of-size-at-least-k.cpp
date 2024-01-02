//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long currSum = 0;
        long long maxi = INT_MIN;
        long long negSum = 0;
        int i = 0, j = 0;
        while(j < n) {
            currSum += a[j];
            if(j - i + 1 < k) {
                j++;
            }
            else if(j - i + 1 == k) {
                maxi = max(maxi, currSum);
                j++;
            }
            else {
                maxi = max(maxi, currSum);
                negSum += a[i++];
                
                if(negSum < 0) {
                    currSum -= negSum;
                    maxi = max(maxi, currSum);
                    negSum = 0;
                }
                
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends