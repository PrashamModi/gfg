//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int minus = 1;
        int i = 0;
        if(s[i] == '-') {
            i++;
            minus = -1;
        }
        int ans = 0;
        int f = true;
        for(; i < s.length() && f; i++) {
            if(s[i] >= '0' && s[i] <= '9')
                ans = (ans * 10) + (s[i] - '0');
            else {
                f = false;
            }
        }
        if(!f) return -1;
        return minus * ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends