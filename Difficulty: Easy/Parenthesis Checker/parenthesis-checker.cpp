//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        vector<char> v;
        for(auto it : x){
            if(it == '(' || it == '{' || it == '[') v.push_back(it);
            else {
                if(v.size() == 0) return false;
                if(it == ')' && v.back() == '(' || it == '}' && v.back() == '{' || it == ']' && v.back() == '[') v.pop_back();
                else return false;
            }
        }
        return v.size() == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends