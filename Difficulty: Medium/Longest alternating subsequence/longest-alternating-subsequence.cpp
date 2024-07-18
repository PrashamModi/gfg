//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind, int currSearch, vector<int> &arr) {
        int res = 0;
        int prev = 0;
        while(ind < arr.size()) {
            if(currSearch == 1 && arr[ind] > arr[prev]) {
                res++;
                currSearch ^= 1;
                prev = ind;
            }
            else if(currSearch == 0 && arr[ind] < arr[prev]) {
                res++;
                currSearch ^= 1;
                prev = ind;
            }
            ind++;
        }
        return res;
    }
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n = arr.size();
    if (n == 0) return 0;

    int maxLen = 1; // Initialize maximum length as 1

    // Function to find the length of the alternating sequence starting with currSearch = 0
    auto searchSequence = [&](bool startWithLarger) -> int {
        int lgt = 1;
        bool currSearch = startWithLarger; // false for looking for a bigger element, true for looking for a smaller element
        int currentElement = arr[0];

        for (int i = 1; i < n; ++i) {
            if (currSearch && arr[i] < currentElement) {
                // Looking for smaller and found smaller
                currentElement = arr[i];
                lgt++;
                currSearch = !currSearch;
            } else if (!currSearch && arr[i] > currentElement) {
                // Looking for bigger and found bigger
                currentElement = arr[i];
                lgt++;
                currSearch = !currSearch;
            } else {
                // Just update the current element and continue
                currentElement = arr[i];
            }
        }
        return lgt;
    };

    // Calculate the two possible lengths and find the maximum
    int maxLen1 = searchSequence(false);
    int maxLen2 = searchSequence(true);

    return max(maxLen1, maxLen2);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends