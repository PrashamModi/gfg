//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> ans;
	void f(int c0, int c1, string s, int n)  {
	    if(n == s.length()) {
	        if(c1 >= c0) {
	            ans.push_back(s);
	            return;
	        }
	    }
	    if(c0 <= c1) {
	        f(c0 + 1, c1, s + "0", n);
	        f(c0, c1 + 1, s + "1", n);
	    }
	}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    f(0, 0, "", n);
	    reverse(ans.begin(), ans.end());
	    return ans;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends