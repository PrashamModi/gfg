//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        //Bijection
        if(str1.length() != str2.length()) return false;
        unordered_map<char, int> m, mpp;
        for(int i = 0; i < str1.length(); i++) {
            if(m.count(str1[i]) == 0 || m[str1[i]] == str2[i]) {
                m[str1[i]] = str2[i];
            }else return false;
            
            if(mpp.count(str2[i]) == 0 || mpp[str2[i]] == str1[i]) {
                mpp[str2[i]] = str1[i];
            }else return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends