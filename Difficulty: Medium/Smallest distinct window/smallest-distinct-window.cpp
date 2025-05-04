//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char, int> m;
        for(auto it : str) m[it]++;
        int required = m.size();
        m.clear();
        int ans = INT_MAX;
        int n = str.size();
        int i = 0, j = 0;
        while(j < n) {
            m[str[j]]++;
            while(m.size() == required) {
                ans = min(ans, j - i + 1);
                // cout<<i<<" "<<j<<endl;
                // cout<<"---> "<<m.size()<<endl;
                m[str[i]]--;
                if(m[str[i]] == 0) {
                    m.erase(str[i]);
                }
                i++;
                if(i >= n) break;
            }
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends