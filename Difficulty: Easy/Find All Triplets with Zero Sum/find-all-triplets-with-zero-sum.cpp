//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>ans;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                int sum = arr[i] + arr[j];
                mp[sum].push_back({i, j});
            }
        }
        for(int k=0;k<arr.size();k++){
            int target=-arr[k];
            auto it = mp.find(target);
            if(it!=mp.end()){
                for (const auto& pair : it->second) {
                int i=pair.first;
                int j=pair.second;
                if(i<j && j<k){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                }
            }
        }
        return ans;

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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends