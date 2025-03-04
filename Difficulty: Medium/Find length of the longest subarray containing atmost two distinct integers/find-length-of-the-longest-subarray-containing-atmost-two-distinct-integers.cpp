//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int ans = 0;
        unordered_map<int, int> m;
        int i = 0, j = 0, n = arr.size();
        while(j < n) {
            m[arr[j]]++;
            while(i <= j && m.size() > 2) {
                m[arr[i]]--;
                if(m[arr[i]] == 0) m.erase(arr[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends