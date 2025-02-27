//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st;
    int mini;
    Solution() {
        // code here
        mini = INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code 
        if(st.empty()) {
            st.push(x);
            mini = x;
        }else{
            if(x < mini){
                st.push(2 * x - mini);
                mini = x;
            }
            else{
                st.push(x);
            }
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()) return;
        int el = st.top();
        st.pop();
        if(el < mini) {
            mini = 2 * mini - el;
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()) return -1;
        long long el = st.top();
        if (el < mini) return mini;
        return el;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()) return -1;
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends