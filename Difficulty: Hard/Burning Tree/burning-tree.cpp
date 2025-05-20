//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void fillParent(Node* root, unordered_map<Node*, Node*> &parentOf) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->left) {
                parentOf[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parentOf[node->right] = node;
                q.push(node->right);
            }
        }
    }

    Node* findNode(Node* root, int start) {
        if(!root) return NULL;
        if(root->data == start) return root;
        Node* left = findNode(root->left, start);
        if(left) return left;
        return findNode(root->right, start);
    }
    
    int minTime(Node* root, int start) {
        unordered_map<Node*, Node*> parentOf;
        fillParent(root, parentOf);


        unordered_map<Node*, bool> vis;
        Node* strt = findNode(root, start);
        vis[strt] = true;

        int currLevel = 0;
        queue<Node*> q;
        q.push(strt);

        while(!q.empty()) {
            int sz = q.size();
            bool f = false;
            for(int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    f = true;
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    f = true;
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parentOf.count(node) && !vis[parentOf[node]]) {
                    f = true;
                    vis[parentOf[node]] = true;
                    q.push(parentOf[node]);
                }
            }
            if(f) currLevel++;
        }
        return currLevel;

    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends