//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int firstOne(const string &s) {
        int index = 0;
        int len = s.size();
        while(index < len && s[index] != '1') index = index + 1;
        return index;
    }
  
    string addBinary(string& s1, string& s2) {
        string res = ""; // result
        
        // i1 traverse s1 , i2 traverses from s2
        // from right to left
        int i1 = s1.size() - 1 , i2 = s2.size() - 1;
        int carry = 0; // carry variable , initially 0
        
        // p1 -> index of first 1 from left in s1
        // p2 -> index of first 1 from left in s2 
        int p1 = firstOne(s1) , p2 = firstOne(s2);
        int val1 , val2 , sum;
        
        while(i1 >= p1 || i2 >= p2) 
        {
            val1 = s1[i1] - '0' ? i1 >= p1 : 0; // value at i1 , if i1 >= p1
            val2 = s2[i2] - '0' ? i2 >= p2 : 0; // value at i2 , if i2 >= p2
            
            sum = val1 + val2 + carry; // value at i1 + value at i2 + previous carry
            carry = 1 ? sum > 1 : 0; // update carry for further additions
            res = res + (char)(sum % 2 + '0'); // add sum % 2 to result
            if(i1 >= p1) i1 = i1 - 1; // decrement i1
            if(i2 >= p2) i2 = i2 - 1; // decerement i2
        }
        
        // if carry is left , then add 1
        if(carry == 1)  res = res + '1';
        reverse(begin(res) , end(res)); // reverse result
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends