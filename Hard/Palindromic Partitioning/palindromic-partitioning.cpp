//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i,int j,string str){
       while(i<j){
          if(str[i]!=str[j]) return 0;
          i++;
          j--;
       }
       return 1;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n + 1, 0);
        for(int ind = n - 1; ind >= 0; ind--){
            int mini = INT_MAX;
            for(int i = ind; i < n; i++){
                if(isPalindrome(ind, i, str)){
                    int cost = 1 + dp[i + 1];
                    mini = min(mini, cost);
                }
            }
            dp[ind] = mini;
        }
        return dp[0] - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends