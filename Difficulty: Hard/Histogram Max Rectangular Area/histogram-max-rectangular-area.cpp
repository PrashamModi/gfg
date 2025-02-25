//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> st;
        int maxA = 0;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                int ele = st.top();
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                maxA = max(maxA, arr[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
    while(!st.empty()) {
            int ele = st.top();
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();
            maxA = max(maxA, arr[ele] * (nse - pse - 1));
        }
        return maxA;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends