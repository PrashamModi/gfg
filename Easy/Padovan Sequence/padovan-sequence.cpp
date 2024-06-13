//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       int mod = 1e9+7;
       int one=1,two=1,three=1;
       for(int i=3;i<=n;i++){
           int temp = (one + two)%mod;
           one = two%mod;
           two = three%mod;
           three = temp%mod;
       }
       return three;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends