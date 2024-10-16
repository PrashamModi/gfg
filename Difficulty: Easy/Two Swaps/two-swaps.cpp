//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
         int n=arr.size();
        int mismatch=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) mismatch++;
        }
        if(mismatch==0|| mismatch==3) return true;
        if(mismatch==1 || mismatch==2 || mismatch > 4) return false;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) {
                swap(arr[i],arr[arr[i]-1]);
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) {
                swap(arr[i],arr[arr[i]-1]);
                break;
            }
        }
        mismatch=0;
         for(int i=0;i<n;i++){
            if(arr[i]!=i+1) mismatch++;
        }
        if(mismatch==0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends