//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        
        vector<int>ans(32,0);
        long long temp=x;
        int index=0;
        while(temp)
        {
           ans[index++]=temp%2;
           temp=temp/2;
        }
        
        
        reverse(ans.begin(),ans.end());
        
        
        long long rd=0;
        for(int i=0;i<ans.size();i++)
        {if(ans[i]==1)
            rd+=pow(2,i);
        }
        
        return rd;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends