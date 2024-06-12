//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;  
        // Step 1: Initialize a counter to zero
        
        for (int i = 1; i <= n; i++) {  
       // Step 2: Loop through each number from 1 to n
            
       std::string numStr = std::to_string(i);  
       // Step 3: Convert the current number to a string
            
            if (numStr.find('4') != std::string::npos) {  
              // Step 4: Check if the string contains the character '4'
               
           count++;  
           // Step 5: If it does, increment the counter

            }
        }
        
        return count;  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends