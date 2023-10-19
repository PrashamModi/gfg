//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int n, vector<int> adj[], int x) 
	{
	    // code here
	    vector<int> vis(n, 0);
	    queue<pair<int, int>> q;
	    q.push({0, 0});
	    
	    while(!q.empty()) {
	        int node = q.front().first;
	        int level = q.front().second;
	        q.pop();
	        if(node == x) return level;
	        vis[node] = 1;
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push({it, level + 1});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends