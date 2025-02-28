//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> s;
        
        s.push(stoi(arr[0]));
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                
                if(arr[i] == "+") s.push(num1+num2);
                else if (arr[i] == "-") s.push(num2-num1);
                else if (arr[i] == "*") s.push(num2*num1);
                else if (arr[i] == "/") s.push(num2/num1);
                
            } else s.push(stoi(arr[i]));
        }
        
        return s.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends