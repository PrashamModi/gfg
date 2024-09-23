//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int, int> temp;
        vector<int> res;
        res.push_back(0);
        res.push_back(0);
        for(int i=0; i<arr.size(); i++)
        {
            if(temp.find(arr[i]) == temp.end() )
            {
                temp[arr[i]] = 1;
            }
            else
            {
                temp[arr[i]] += 1; // repeating element
                res[0] = arr[i];
            }
        }
        for(int i=1; i<=arr.size(); i++)
        {
            if(temp.find(i) == temp.end()) // missing element
            {
              res[1] = i;
              break;
            }
        }
         return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends