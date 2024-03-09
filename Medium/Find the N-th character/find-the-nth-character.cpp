//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
         int ind=0;
        long long maxm=pow(2,r);
        while(maxm-1<n){
            n-=maxm;
            ind++;
        }
        bool flag=true;
        while(n>0){
            maxm>>=1;
            if(n>=maxm){
                flag=!flag;
                n-=maxm;
            }
        }
        if(flag)return s[ind];
        else return s[ind]=='1'?'0':'1';
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends