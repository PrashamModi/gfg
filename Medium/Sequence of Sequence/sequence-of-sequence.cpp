//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int first, int last, int n) {
        if(n == 0) return 1;
        if(first > last) return 0;
        
        int notTake = f(first + 1, last, n);
        int take = f(2 * first, last, n - 1);
        
        return notTake + take;
    }
    int numberSequence(int m, int n){
        // code here
        return f(1, m, n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends