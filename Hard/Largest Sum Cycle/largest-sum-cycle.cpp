//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long ans = -1;
  void dfs(int node, vector<int> &edge, vector<int> &vis, vector<int> &pathvis){
      vis[node] = 1;
      pathvis[node] = 1;
      if(edge[node] != -1){
          int adj = edge[node];
          if(!vis[adj]){
              dfs(adj, edge, vis, pathvis);
          }
          else if(pathvis[adj]){
              long long sum = 0;
              vector<int> chk(edge.size(), 0);
              while(!chk[adj]){
                  chk[adj] = 1;
                  sum += adj;
                  adj = edge[adj];
              }
              ans = max(ans, sum);
          }
      }
      pathvis[node] = 0;
  }
  long long largestSumCycle(int n, vector<int> edge)
  {
    // code here
    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, edge, vis, pathvis);
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends