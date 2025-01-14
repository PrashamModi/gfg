//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
         int totalsum=0;
       int leftsum=0;
       int n=arr.size();
       for(int i=0;i<n;i++){
           totalsum+=arr[i];
       }
       for(int i=0;i<n;i++){
           //totalsum=leftsum+rightsum
           //rightsum=totalsum-leftsum
           totalsum-=arr[i];//leftsum decreasing from totalsum
           if(leftsum==totalsum){
               return i;
           }
           leftsum+=arr[i]; //updating leftsum index wise
       }
      return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends