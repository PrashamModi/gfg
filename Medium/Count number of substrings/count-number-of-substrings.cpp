//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int f(string &s, int k) {
        long long ans = 0;
    	int j = 0;
    	int m[26] = {0};
    	int disChar = 0;
    	for(int i = 0; i < s.size(); i++){
    	    m[s[i] - 'a']++;
    	    if(m[s[i] - 'a'] == 1) disChar++;
    	    while(disChar > k){
    	        m[s[j] - 'a']--;
    	        if(m[s[j] - 'a'] == 0) disChar--;
    	        j++;
    	    }
    	    ans += (i - j + 1);
    	}
    	return ans;
    } 
    long long int substrCount (string s, int k) {
    	//code here.
    	return f(s, k) - f(s, k - 1);
    	
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends