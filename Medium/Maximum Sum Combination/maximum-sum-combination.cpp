//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ans(k, 0);
        
        int ind = 0;
        set<pair<int, int>> s;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
        s.insert({n - 1, n - 1});
        
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int sum = pq.top().first;
            pq.pop();
            
            if(x >= 1 && s.find({x - 1, y}) == s.end()){
                pq.push({a[x - 1] + b[y], {x - 1, y}});
                s.insert({x - 1, y});
            }
            
            if(y >= 1 && s.find({x, y - 1}) == s.end()){
                pq.push({a[x] + b[y - 1], {x, y - 1}});
                s.insert({x, y - 1});
            }
            
            ans[ind++] = sum;
            if(ind == k) return ans;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends