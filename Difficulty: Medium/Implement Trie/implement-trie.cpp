//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag;}
};
class Trie {
  public:
    Node* root;
    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found,
                // the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node
        // marks the end of a word
        return node->isEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends