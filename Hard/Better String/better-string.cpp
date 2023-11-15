//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(string str) {
        unordered_map<char, int> m;
        int count = 1;
        for(auto it : str) {
            int newCount = 2 * count;
            if(m.find(it) != m.end()) {
                newCount -= m[it];
            }
            m[it] = count;
            count = newCount;
        }
        return count;
    }
    string betterString(string str1, string str2) {
        int cnt1 = f(str1);
        int cnt2 = f(str2); 
        
        if(cnt2 > cnt1) return str2;
        return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends