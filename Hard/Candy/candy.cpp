//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &rat) {
        // code here
         // code here
        vector<int> v(rat.size(),1);
        for(int i=1;i<rat.size();i++){
            if(rat[i]>rat[i-1]){
                v[i]=v[i-1]+1;
            }
        }
        for(int i=rat.size()-2;i>=0;i--){
            if(rat[i]>rat[i+1]){
                v[i]=max(v[i],v[i+1]+1);
            }
        }
        int sum=0;
        for(auto x:v)sum+=x;
        return sum;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends