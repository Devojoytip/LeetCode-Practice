// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *r) {
        // Your Code Here
        if(!r) return {};
        
        vector<int> res;
        
        map<int,Node *> mp;
        
        queue<pair<Node *,int>> q;
        q.push({r,0});
        
        while(q.size())
        {
            auto curr=q.front();
            q.pop();
            
            Node * temp=curr.first;
            int lev=curr.second;
            
            mp[lev]=temp;
            
            if(temp->left) q.push({temp->left,lev-1});
            if(temp->right) q.push({temp->right,lev+1});
        }
        
        for(auto it: mp) res.push_back(it.second->data);
        
        return res;
    }
};
