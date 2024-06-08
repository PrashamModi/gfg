//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        if(arr1[0] != arr2[0]) return 0 ;
        if(arr1[n - 1] != arr2[n - 2]) return n - 1 ;
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr1[mid] == arr2[mid]) {
                low = mid + 1;
            }
            else if(arr1[mid] != arr2[mid]) {
                ans = mid;
                high = mid - 1;
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
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends