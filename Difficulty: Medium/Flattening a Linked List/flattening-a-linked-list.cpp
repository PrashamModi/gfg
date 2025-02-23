//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge(Node* list1, Node* list2) {
        Node* dNode = new Node(-1);
        Node* temp = dNode;
        
        while(list1 && list2) {
            if(list1->data < list2->data) {
                temp->bottom = list1;
                temp = list1;
                list1 = list1->bottom;
            }else{
                temp->bottom = list2;
                temp = list2;
                list2 = list2->bottom;
            }
            temp->next = NULL;
        }
        if(list1) temp->bottom = list1;
        else temp->bottom = list2;
        
        if(dNode->bottom){
            dNode->bottom->next = NULL;
        }
        
        return dNode->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root == NULL || root->data == NULL){
            return root;
        }
        Node* mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends