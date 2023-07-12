// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *r)
    {
        //Your code here
        
        if(!r) return {};
        
        vector<int> res;
        queue<pair<Node *,int>> q;
        map<int,Node *> mp;
        q.push({r,0});
        
        while(q.size())
        {
            auto curr=q.front();
            q.pop();
            
            Node * temp=curr.first;
            int lev=curr.second;
            
            if(mp.find(lev)==mp.end()) mp[lev]=temp;
            
            if(temp->left) q.push({temp->left,lev-1});
            if(temp->right) q.push({temp->right,lev+1});
        }
        
        for(auto it: mp) res.push_back(it.second->data);
        
        return res;
    }
    
};
