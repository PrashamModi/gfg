//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int one = 0, two = 0, zero = 0;
        int n = s.length();
        int i = 0, j = 0;
        int ans = n + 1;
        while(j < n) {
            if(s[j] == '0') {
                zero++;
                j++;
            }
            else if(s[j] == '1') {
                one++;
                j++;
            }
            else {
                two++;
                j++;
            }
            if(zero > 0 && one > 0 && two > 0) {
                ans = min(ans, j - i);
                while(i < j && (zero > 0 && one > 0 && two > 0)) {
                    if(s[i] == '0') zero--;
                    else if(s[i] == '1') one--;
                    else two--;
                    if(zero>0 && one>0 && two>0){
                      ans=min(ans,j-i-1);
                    }
                    i++;
                }
            }
        }
        return ans == n + 1 ? -1 : ans;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends