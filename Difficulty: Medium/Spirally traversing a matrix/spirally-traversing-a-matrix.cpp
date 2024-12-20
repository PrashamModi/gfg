//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int r = matrix.size();
        int c = matrix[0].size();
        int top  = 0;
        int right = c - 1;
        int left = 0;
        int bottom = r - 1;
        vector<int>ans;
        while((top <= bottom) and (left <= right)){
            //from left to right keeping top fix
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
                top++;
            //from top to bottom keeping right fix
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
                right--;
            //from right to left keeping bottom fix
            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                    bottom--;
            }
            //from bottom to top keeping left fix
            if(left <= right){
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
                left++;
            }
        }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends