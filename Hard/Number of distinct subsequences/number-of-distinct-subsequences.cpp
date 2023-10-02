//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#define rep(i,a,b) for(int i=a;i<b;i++)

long long int c = (1e9)+7;

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_map<char,long long int> mp;
	    long long int ans=1;
	    rep(i,0,s.length()){
	       long long int t= mp[s[i]];
	       mp[s[i]]=(ans%c);
	       ans+=((ans-t)%c);
	    }
	    return ans%(c);
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends