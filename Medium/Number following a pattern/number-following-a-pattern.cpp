//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        string ans = "";
        int n = s.size();
        for(int i = 1; i <= n + 1; i++) {
            ans += to_string(i);
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == 'I') continue;
            int cnt = 1;
            int j = i;
            while(i < n && s[i] == 'D') {
                cnt++;
                i++;
            }
            reverse(ans.begin() + j, ans.begin() + j + cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends