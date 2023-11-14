//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n1=s1.size(), n2=s2.size();
        if(n1!=n2) return false;
        if(s1==s2) return true;
        for(int i=1; i<n1; ++i){
            if(s1.substr(0,i)==s2.substr((n2-i),i) && s1.substr(i,(n1-i))==s2.substr(0,(n2-i))){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends