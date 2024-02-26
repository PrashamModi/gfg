//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void f(int ind, string &s, vector<string> &ans, string curr) {
	        if(ind >= s.length()) {
	            if(curr.size()) ans.push_back(curr);
	            return ;
	        }
	        f(ind + 1, s, ans, curr);
	        curr.push_back(s[ind]);
	        f(ind + 1, s, ans, curr);
	        curr.pop_back();
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string curr = "";
		    f(0, s, ans, curr);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends