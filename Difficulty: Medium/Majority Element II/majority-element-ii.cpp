//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n=arr.size();
        int c1=0,c2=0,e1=-1,e2=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==e1){
                c1++;
            }else if(arr[i]==e2){
                c2++;
            }else if(c1==0){
                e1=arr[i];
                c1=1;
            }else if(c2==0){
                e2=arr[i];
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i:arr){
            if(i==e1) c1++;
            else if(i==e2) c2++;
        }
        vector<int> result;
        if (c1 > n / 3) result.push_back(e1);
        if (c2 > n / 3) result.push_back(e2);
    
        if (result.size() == 2 && result[0] > result[1]) swap(result[0], result[1]);
    
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends