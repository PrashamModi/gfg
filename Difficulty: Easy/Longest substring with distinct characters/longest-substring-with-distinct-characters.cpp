//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
         int i = 0;
        int j = 0;
        int l = 0;  // Initialize the length of the longest substring
        vector<int> count(26, 0);  // Array to keep track of character frequencies
        
        int n = s.size();  // Get the length of the string
        
        // Loop through the string using two pointers, i and j
        while (i < n && j < n) {
            count[s[j] - 'a']++;  // Increment the count of the current character
            
            // If the count of the current character is more than 1, we have a duplicate
            if (count[s[j] - 'a'] > 1) {
                // Move the left pointer i until the duplicate character count is reduced to 1
                while (count[s[j] - 'a'] > 1) {
                    count[s[i] - 'a']--;
                    i++;
                }
            }
            
            // Update the length of the longest substring with unique characters
            l = max(l, j - i + 1);
            j++;
        }
        
        return l;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends