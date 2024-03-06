//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector <int> ans;
            int i = 0, p = 0;
            int k = pattern.size();
            int n = text.size();
            while(i < n-k+1){
                p = i;
                int l = 0;
                while(pattern[l] == text[p] && l < k){
                    p++;
                    l++;
                }
                if(l == k){
                    ans.push_back(i+1);
                }
                i++;
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends