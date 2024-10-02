//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n=arr.size(),c=0;
        if(n==1)return arr[0];
        if(n%2==0){
            for(int i=1; i<=n; i++){
                if(n==c+2 || n==c+4)return arr[i];
                c=c+4;
            }
        }else{
        c=1;
             for(int i=2; i<=n; i++){
                if(n==c+2 || n==c+4)return arr[i];
                c=c+4;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends