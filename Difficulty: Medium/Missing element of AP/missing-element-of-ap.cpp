//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        unordered_map<int, int> m;
        for(int i = 1; i < arr.size(); i++) {
            m[arr[i] - arr[i - 1]]++;
        }
        if(m.size() == 1) return arr[arr.size() - 1] + (arr[1] - arr[0]);
        int addFreq = -1;
        for(auto it : m) if(it.second > 1) addFreq = it.first;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] != (arr[i - 1] + addFreq)){
                return arr[i - 1] + addFreq;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends