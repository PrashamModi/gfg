//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();
    int sum1 = 0, sum2 = 0;
    int res = 0;

    // Traverse both arrays simultaneously
    while(i < n && j < m) {
        // Add elements to sum1 from arr1 if arr1[i] is smaller
        if(arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        }
        // Add elements to sum2 from arr2 if arr2[j] is smaller
        else if(arr1[i] > arr2[j]) {
            sum2 += arr2[j++];
        }
        // When common element is found
        else {
            res += max(sum1, sum2) + arr1[i];
            sum1 = 0; // Reset sum1
            sum2 = 0; // Reset sum2
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while(i < n) {
        sum1 += arr1[i++];
    }

    // Add remaining elements of arr2
    while(j < m) {
        sum2 += arr2[j++];
    }

    // Add the maximum of the remaining sums to the result
    res += max(sum1, sum2);

    return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends