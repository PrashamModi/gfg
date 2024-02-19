//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<int> heap;
        for(auto s:mp){
            heap.push(s.second);
        }
        int x;
        while(k--){
            x = heap.top();
            heap.pop();
            heap.push(x-1);
        }
        int ans = 0;
        while(!heap.empty()){
            x=heap.top();
            ans += x*x;
            heap.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends