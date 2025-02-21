//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch); 
            }
            else{
                if(st.empty())  return false;
                if((st.top()=='(' && ch==')') || (st.top()=='{' && ch=='}')||(st.top()=='[' && ch==']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty())   return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends