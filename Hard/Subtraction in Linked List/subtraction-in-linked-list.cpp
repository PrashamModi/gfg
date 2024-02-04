//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> subtract(vector<int>&v1,vector<int>&v2){
        int borrow=0,i=v1.size()-1,j=v2.size()-1;
        vector<int>p;
        while(i>=0&& j>=0){
            if(v1[i]>=v2[j]){
                 borrow=0;
                 p.push_back(v1[i]-v2[j]);
                 i--,j--;
            }
            else{
                int k=i-1;
                while(k>=0&&v1[k]==0){
                    v1[k]=9,k--;
                }
                if(k>=0&&v1[k]>0){
                    v1[k]-=1;
                }
                p.push_back(v1[i]+10-v2[j]);
                i--,j--;
            }
        }
        while(i>=0){
            if(borrow+v1[i]>=0){
                borrow=0;
                 p.push_back(v1[i]+borrow);
                 i--;
            }
        }
        return p;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        vector<int>v1,v2;
        while(head1!=NULL&& head1->data==0){
            head1=head1->next;
        }
         while(head2!=NULL&& head2->data==0){
            head2=head2->next;
        }
        while(head1!=NULL) {
            v1.push_back(head1->data);
            head1=head1->next;
        }
        while(head2!=NULL) {
            v2.push_back(head2->data);
            head2=head2->next;
        }
        vector<int>ans;
        if(v1.size()>v2.size()){
              ans=subtract(v1,v2);
        }
        else if(v1.size()==v2.size()){
            int i=0,j=0;
            while(i<v1.size() && v1[i]==v2[i]) i++;
            if(i<v1.size()){
                if(v1[i]>v2[i]) ans=subtract(v1,v2);
                else ans=subtract(v2,v1);
            }
        }
        else{
            ans=subtract(v2,v1);
        }
        int i=0;
        reverse(ans.begin(),ans.end());
        while(i<ans.size()&& ans[i]==0) i++;
        for(;i<ans.size();i++){
            cout<<ans[i];
        }
        if(ans.size()==0) cout<<"0";
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends