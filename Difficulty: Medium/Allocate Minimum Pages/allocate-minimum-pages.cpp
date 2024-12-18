//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool check(vector<int> &arr, int k, int mid) {
        int cnt = 1;  // Count of students needed
        int sum = 0;  // Current sum of pages assigned to a student

        // Iterate through books
        for (int i = 0; i < arr.size(); ++i) {
            // If adding the current book exceeds `mid`, assign to the next student
            if (sum + arr[i] <= mid) {
                sum += arr[i];  // Add pages of the current book
            } else {
                sum = arr[i];   // Reset sum to current book's pages
                cnt++;          // Increment student count
            }
        }

        // Return true if the number of students is within the limit
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (k > n) return -1;  // Not enough books for each student

        // Set binary search bounds
        int low = *max_element(arr.begin(), arr.end());         // Largest single book pages
        int high = accumulate(arr.begin(), arr.end(), 0ll);    // Total pages of all books
        int ans = -1;

        // Binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Midpoint of current range

            // Validate allocation using `check`
            if (check(arr, k, mid)) {
                ans = mid;          // Update answer if feasible
                high = mid - 1;     // Search for a smaller maximum
            } else {
                low = mid + 1;      // Increase the range
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends