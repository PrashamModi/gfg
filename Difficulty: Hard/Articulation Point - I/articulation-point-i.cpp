//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
  private:
    int timer = 0;
  public:
    void dfs(int node, int par, vector<int> &timeOfInsertion, vector<int> &lowestTime, vector<int> &mark, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        lowestTime[node] = timeOfInsertion[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, node, timeOfInsertion, lowestTime, mark, vis, adj);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
                if(lowestTime[it] >= timeOfInsertion[node] && par != -1) {
                    mark[node] = 1;
                }
                child++;
            }else{
                lowestTime[node] = min(lowestTime[node], timeOfInsertion[it]);
            }
        }
        if(par == -1 && child > 1) mark[node] = 1;
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n, 0);
        vector<int> timeOfInsertion(n), lowestTime(n);
        vector<int> mark(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, timeOfInsertion, lowestTime, mark, vis, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size() == 0) ans.push_back(-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends