//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int closestSum=INT_MAX;
        int closestDiff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int left=i+1,right=n-1;
            while(left<right)
            {
                int currentSum = arr[i]+arr[left]+arr[right];
                int currentDiff = abs(currentSum-target);
                if(currentDiff<closestDiff||(currentDiff==closestDiff&& currentSum>closestSum)){
                    closestDiff=currentDiff;
                    closestSum=currentSum;
                }
                
                if(currentSum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }//i close
        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends