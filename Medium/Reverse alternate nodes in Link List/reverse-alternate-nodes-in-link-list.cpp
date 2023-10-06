//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        // 10 -> 4 -> 9 -> 1 -> 3 -> 5 -> 9 -> 4
        // 10 -> 9 -> 3 -> 9 -> 4 -> 5 -> 1 -> 4 ->null
        Node *curr = odd;
        Node *nxt = odd;
        Node* prev = nullptr;
        Node *secondCurr = NULL;
        while(curr && curr -> next) {
            secondCurr = curr->next;
            curr->next = secondCurr->next;
            secondCurr->next = prev;
            prev = secondCurr;
            nxt = curr->next;
            if(!curr->next) {
                nxt = curr;
            }
            curr = curr->next;
        }
        nxt->next = secondCurr;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends