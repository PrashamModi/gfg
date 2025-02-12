//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<vector<string>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;
        int level = 0;
        while(!q.empty()) {
            vector<string> curr = q.front();
            q.pop();
            
            if(level < curr.size()) {
                level++;
                for(auto it : usedOnLevel) s.erase(it);
            }
            string word = curr.back();
            
            if(word == endWord) {
                if(ans.size() == 0) ans.push_back(curr);
                else if(curr.size() == ans[0].size()) ans.push_back(curr);
            }
            
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    if(s.find(word) != s.end()) {
                        usedOnLevel.push_back(word);
                        curr.push_back(word);
                        q.push(curr);
                        curr.pop_back();
                    }
                }
                word[i] = ch;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends