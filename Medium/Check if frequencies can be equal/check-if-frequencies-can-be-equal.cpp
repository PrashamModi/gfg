//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> freq(26, 0);
	    for(auto &it : s) {
	        freq[it - 'a']++;
	    }
	    int should = -1;
	    int cnt = 0;
	    for(int i = 0; i < 26; i++) {
	        if(freq[i]) {
	            if(should == -1) should = freq[i];
	            else if(abs(should - freq[i]) > 1) return false;
	            else if(abs(should - freq[i]) == 1 && ++cnt > 1) return false;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends