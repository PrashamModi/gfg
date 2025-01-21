//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node * reverse(Node* head)
  {
      Node* curr=head;
      Node* prev=NULL;
      
      while(curr!=NULL)
      {
          Node* next=curr->next;
          
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
  }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node *prev=NULL;
        Node * newH=NULL;
        
        Node *curr=head;
        int c=0;
        int flag=0;
        Node *x=head;
        while(curr!=NULL)
        {
            c++;
            Node* next=curr->next;
            if(c==k || curr->next==NULL)
            {
                curr->next=NULL;
                Node* y= reverse(x);
                // cout<<y->data<<endl;
                if(flag==0)
                {
                    flag=1;
                    newH=y;
                }
                if(prev==NULL)
                {
                    prev=x;
                }
                else
                {
                    prev->next=y;
                    prev=x;
                }
                c=0;
                x=next;
            }
            curr=next;
        }
        return newH;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends