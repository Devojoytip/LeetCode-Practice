//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // vector <int> boundary(Node *root)
    // {
    //     //Your code here
    // }
    
    bool isLeaf(Node *r)
    {
        return r and !r->left and !r->right;
    }

    void addLeft(Node *r, vector<int> &res)
    {
        if(!r or isLeaf(r)) return;
    
        Node* t=r->left;
        
        while(t)
        {
            if(!isLeaf(t)) res.push_back(t->data);
    
            if(t->left) t=t->left;
            else t=t->right;
        }
    }

    void addRight(Node *r, vector<int> &res)
    {
        if(!r or isLeaf(r)) return;
        
        vector<int> v;
        Node* t=r->right;
    
        while (t) 
        {
            if (!isLeaf(t)) v.push_back(t->data);
    
            if (t->right) t = t->right;
            else t = t->left;
        }
    
        for (int i = v.size() - 1; i >= 0; i--) res.push_back(v[i]);
    }
    
    void addLeaves(Node *r, vector<int> &res)
    {
        if(!r) return;
        
        if(isLeaf(r))
        {
            res.push_back(r->data);
            return;
        }
    
        if(r->left) addLeaves(r->left, res);
        if(r->right) addLeaves(r->right, res);
    }
    
    vector<int> boundary(Node *r)
    {
    	// Write your code here.
        
        if(!r) return {};
        vector<int> res;
        if(!isLeaf(r)) res.push_back(r->data);
        
        addLeft(r, res);
        
        addLeaves(r, res);
        
        addRight(r, res);
        
        return res;
    }

};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends