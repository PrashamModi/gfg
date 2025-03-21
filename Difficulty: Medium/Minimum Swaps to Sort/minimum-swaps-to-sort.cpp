//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<pair<int, int>> v(n);
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) v[i] = {arr[i], i};
        sort(v.begin(), v.end());
        int ans  = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] || v[i].second == i) continue;
            int cycleSz = 0;
            int j = i;
            while(!vis[j]) {
                cycleSz++;
                vis[j] = 1;
                j = v[j].second;
            }
            if(cycleSz) ans += (cycleSz - 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends