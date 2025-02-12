//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        if(startWord == targetWord) return 0;
        q.push({startWord, 1});
        while(!q.empty()) {
            string word = q.front().first;
            int currSteps = q.front().second;
            q.pop();
            if(word == targetWord) return currSteps;
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(s.find(word) != s.end()) {
                        q.push({word, currSteps + 1});
                        s.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends