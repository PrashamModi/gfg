//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DSU{
    public:
    vector<int>size;
    vector<int>par;
    DSU(int n)
    {
        size.resize(n,1);
        par.resize(n);
        for (int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int node)
    {
        if (node==par[node]) return node;
        return par[node]=findPar(par[node]);
    }
    void unions(int u,int v)
    {
        u=findPar(u);
        v=findPar(v);
        if (u==v) return;
        if (size[u]>size[v])
        {
            par[v]=u;
            size[u]+=size[v];
        }
        else{
            par[u]=v;
            size[v]+=size[u];
        }
    }
    int getSize(int n)
    {
        int node=findPar(n);
        return size[node];
    }
};

bool isValid(int row,int col,vector<vector<int>>&grid)
{
    return row>=0 && col>=0 && row<grid.size() && col<grid.size() && grid[row][col]==1;
}
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        DSU dsu(n*n);
        int deli[]={1,-1,0,0};
        int delj[]={0,0,1,-1};
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]==1)
                {
                    for (int k=0;k<4;k++)
                    {
                        int newi=i+deli[k];
                        int newj=j+delj[k];
                        if (isValid(newi,newj,grid))
                        {
                           dsu.unions(i*n+j,newi*n+newj); 
                        }
                    }
                }
            }
        }
        
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]==1)
                {
                    ans=max(ans,dsu.getSize(i*n + j));
                    
                }
                else{
                    set<int>st;
                     int curSize=1;
                    for (int k=0;k<4;k++)
                    {
                        int newi=i+deli[k];
                        int newj=j+delj[k];
                        
                        if (isValid(newi,newj,grid))
                        {
                            st.insert(dsu.findPar(newi*n + newj));
                        }
                    }
                    for (auto it: st)
                    {
                        curSize+=dsu.getSize(it);
                    }
                    ans=max(ans,curSize);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends