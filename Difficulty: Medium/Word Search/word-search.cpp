//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, int j, int ind, vector<vector<char>> &mat, string &word) {
        if(ind >= word.size()) return true;
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[ind]) return false;
        char ch = mat[i][j];
        mat[i][j] = '#';
        vector<int> dir = {0, -1, 0, 1, 0};
        bool f = false;
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            f = f || dfs(ni, nj, ind + 1, mat, word);
        }
        mat[i][j] = ch;
        return f;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == word[0] && dfs(i, j, 0, mat, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends