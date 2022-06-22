// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        while(head)
        {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        Node* temp = head;
        int carry = 0;
        while(head)
        {
            if(head->data == 9)
            {
                head->data = 0;
                carry = 1;
            }
            else
            {
                head->data += 1;
                carry = 0;
            }
            
            if(carry == 0)
                break;
                
            head = head->next;
        }
        
        if(carry == 1)
        {
            Node* node = new Node(1);
            node->next = temp;
            temp = node;
            return temp;
        }
        
        return reverse(temp);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends