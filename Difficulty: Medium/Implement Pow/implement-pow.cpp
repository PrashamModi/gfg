//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        if (e == 0) return 1.0; 
        if (e < 0) return 1.0 / power(b, -e); 
    
    
        if (e % 2 == 0) {
            double halfPower = power(b, e / 2);
            return halfPower * halfPower; 
        } 
        else {
            return b * power(b, e - 1); 
        }
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends