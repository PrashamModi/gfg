//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    // Idea is to do a binary search over all distances possible as max distance and check if it requires less
    // than k stations to have a max distance of 'mid', predicate will answer the question "Is the number of 
    // stations required to make the max distance less than equal to mid is less than k"
    
  public:
    bool predicate(vector<int> &stations, int n, double mid, int k){
        int cnt = 0;
        for(int i = 1; i < n; i++)
        {
            cnt += ceil((stations[i] - stations[i - 1]) / mid) - 1;
        }
        return cnt <= k;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double maxdist = 0, left = 0, right = 1e9;
        while(right - left > 1e-6)
        {
            double mid = (left + right) / 2;
            if(predicate(stations, stations.size(), mid, k))
            {
                maxdist = mid;
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return maxdist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends