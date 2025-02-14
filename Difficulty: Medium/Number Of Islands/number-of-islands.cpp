//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
   
public:
 vector<int> rank, parent, size;
    DisjointSet(int n){
       rank.resize(n + 1, 0);
       parent.resize(n + 1);
       size.resize(n + 1, 1);
       for(int i = 0; i <= n; i++){
           parent[i] = i;
       }
    } 
    int findUPar(int node){
       if(parent[node] == node)
           return node;
       return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        DisjointSet ds(n * m);
        for(auto it : operators) {
            int u = it[0];
            int v = it[1];
            
            if(vis[u][v] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[u][v] = 1;
            cnt++;
            vector<int> dir = {0, -1, 0, 1, 0};
            for(int k = 0; k < 4; k++){
                int nu = u + dir[k];
                int nv = v + dir[k + 1];
                if(nu >= 0 && nu < n && nv >= 0 && nv < m && vis[nu][nv] == 1){
                    int currNodeNo = u * m + v;
                    int adjNodeNo = nu * m + nv;
                    if(ds.findUPar(currNodeNo) != ds.findUPar(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(currNodeNo, adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends