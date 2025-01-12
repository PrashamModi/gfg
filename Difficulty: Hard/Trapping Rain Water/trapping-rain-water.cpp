//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int i = 0, j = height.size() - 1;
        int leftmax = 0, rightmax = 0;
        int res = 0;
        while(i <= j){
            if(height[i] <= height[j]){
                if(height[i] >= leftmax)leftmax = height[i];
                else res += leftmax - height[i];
                i++;
            }
            else{
                if(height[j] >= rightmax) rightmax = height[j];
                else res += rightmax - height[j];
                j--;
            }
        }
        return res;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends