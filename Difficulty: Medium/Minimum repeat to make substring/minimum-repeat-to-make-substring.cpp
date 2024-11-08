//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string str="";
        int count=0;
        while(s2.length()>str.length()){
            str+=s1;
            count++;
        }
        if(str.find(s2)!=-1)
        return count;
        str+=s1;
        if(str.find(s2)!=-1)
        return count+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends