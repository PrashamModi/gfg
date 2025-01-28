//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(int ind, string s, vector<string> &ans) {
        if(ind >= s.length()) {
            ans.push_back(s);
            return;
        }
        for(int i = ind; i < s.length(); i++) {
            swap(s[i], s[ind]);
            f(ind + 1, s, ans);
            swap(s[i], s[ind]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        f(0, s, ans);
        set<string> st;
        for(auto it : ans) st.insert(it);
        vector<string> res(st.begin(), st.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends