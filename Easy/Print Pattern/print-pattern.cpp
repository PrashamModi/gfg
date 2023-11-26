//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void f(int curr, int n, vector<int> &ans, int change) {
        ans.push_back(curr);
        if(curr <= 0) change = 5;
        if(curr < n || change == -5) f(curr + change, n, ans, change);
    }
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        f(N, N, ans, -5);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends