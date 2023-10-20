//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int n, pair<int, int> arr[]) {
        // Code here
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<double, int> m;
            double x1 = arr[i].first;
            double y1 = arr[i].second;
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                int x2 = arr[j].first;
                int y2 = arr[j].second;
                if(x1 == x2 && y1 == y2) {
                    cnt++;
                } else {
                    double slope = (x2 - x1) / (y2 - y1);
                    m[slope]++;
                }
            }
            for(auto it : m) {
                ans = max(ans, it.second + cnt);
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
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}
// } Driver Code Ends