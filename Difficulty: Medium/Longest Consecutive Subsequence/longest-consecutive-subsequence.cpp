//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        map<int, int> m;
        for(auto it : arr) m[it] = 1;
        
        int cnt = 1;
        int last = m.begin()->first;
        int maxi = 1;
        for(auto it : m) {
            if(it.first - 1 == last) {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else if(it.first == last) continue;
            else cnt = 1;
            
            last = it.first;
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends