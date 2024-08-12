//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &a, vector<int> &b) {
        // code here
            int n1 = a.size(), n2 = b.size();
            //if n1 is bigger swap the arrays:
            if (n1 > n2) return SumofMiddleElements(b, a);
        
            int n = n1 + n2; //total length
            int left = (n1 + n2 + 1) / 2; //length of left half
            //apply binary search:
            int low = 0, high = n1;
            while (low <= high) {
                int mid1 = (low + high) >> 1;
                int mid2 = left - mid1;
                //calculate l1, l2, r1 and r2;
                int l1 = INT_MIN, l2 = INT_MIN;
                int r1 = INT_MAX, r2 = INT_MAX;
                if (mid1 < n1) r1 = a[mid1];
                if (mid2 < n2) r2 = b[mid2];
                if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
                if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
        
                if (l1 <= r2 && l2 <= r1) {
                    if (n % 2 == 1) return max(l1, l2);
                    else return max(l1, l2) + min(r1, r2);
                }
        
                //eliminate the halves:
                else if (l1 > r2) high = mid1 - 1;
                else low = mid1 + 1;
            }
            return 0;
        
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends