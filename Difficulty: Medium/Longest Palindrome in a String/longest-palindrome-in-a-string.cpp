//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        string ans = "";
        int ansLen = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > ansLen){
                    ans = s.substr(l, r - l + 1);
                    ansLen = r - l + 1;
                }
                l--, r++;
            }
            
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > ansLen){
                    ans = s.substr(l, r - l + 1);
                    ansLen = r - l + 1;
                }
                l--, r++;
            }
        }
        return ans;
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends