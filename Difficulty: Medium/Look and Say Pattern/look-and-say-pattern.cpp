//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
         string ans="";
        
        string k="1";
        for(int i=2;i<=n;i++){
            int count=1;
            char ch=k[0];
            string newstring="";
            for(int j=1;j<k.size();j++){
                if(k[j]==ch){
                    count++;
                }else{
                    newstring+=to_string(count);
                    newstring+=ch;
                    ch=k[j];
                    count=1;
                }
                
            }
            newstring+=to_string(count);
            newstring+=ch;
            k=newstring;
        }
        
        return k;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends