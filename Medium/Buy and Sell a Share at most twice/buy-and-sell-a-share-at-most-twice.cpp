//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
            if(ind == prices.size()) return 0;
            if(cap <= 0) return 0;
            
            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
            if(buy){
                return dp[ind][buy][cap] = max(f(ind+1, 1, cap, prices, dp), -prices[ind] + f(ind+1, 0, cap, prices, dp));
            }
            else{
                return dp[ind][buy][cap] = max(f(ind+1, 0, cap, prices, dp), prices[ind] + f(ind+1, 1, cap - 1, prices, dp));
            }
        }
        int maxProfit(vector<int>&prices){
            //Write your code here..
            int n = prices.size();
            vector<vector<int>> ahead(2,vector<int> (3,0));
        
            vector<vector<int>> curr(2,vector<int> (3,0));
            
            for(int ind = n - 1; ind >= 0; ind--){
                for(int buy = 1; buy >= 0; buy--){
                    for(int cap = 1; cap <= 2; cap++){
                        if(buy){
                            curr[buy][cap] = max(ahead[1][cap], -prices[ind] + ahead[0][cap]);
                        }
                        else{
                            curr[buy][cap] = max(ahead[0][cap], prices[ind] + ahead[1][cap - 1]);
                        }
                    }
                    ahead = curr;
                }
            }
            return ahead[1][2];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends