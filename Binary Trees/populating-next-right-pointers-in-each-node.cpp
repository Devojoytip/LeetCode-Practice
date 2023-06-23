// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

// BFS

class Solution {
public:
    Node* connect(Node* r) 
    {
        if(!r) return r;

        queue<Node*> q;
        q.push(r);

        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
                q.pop();

                if(!q.empty() and i!=n-1) temp->next=q.front();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return r;
    }
};
