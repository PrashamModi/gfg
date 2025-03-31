//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int ans = 0;
        vector<int> last(26, -1);
        for(int i = 0; i < s.length(); i++) last[s[i] - 'a'] = i;
        int currmax = 0;
        for(int i = 0; i < s.length(); i++) {
            currmax = max(currmax, last[s[i] - 'a']);
            if(i == currmax){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends