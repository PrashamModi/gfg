//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, pathVis);
            } 
            if(pathVis[it] == 1) return;
        }
        pathVis[node] = 0;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            dfs(i, adj, vis, pathVis);
        }
        for(int i = 0; i < n; i++) 
           if(pathVis[i] == 0) ans.push_back(i);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends