vector<int> view(Node *r)
{
   // Your code here
   if(!r) return {};
        
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    vector<int> res;
    
    q.push({r, 0});
    
    while(q.size())
    {
        Node* curr=q.front().first;
        int lev=q.front().second;
        q.pop();
        
        if(mp.find(lev)==mp.end()) mp[lev]=curr->data;                         // for left-view
        mp[lev]=curr->data;                                                    // for right-view
        mp[lev]=curr->data;                                                    // for bottom-view
        if(mp.find(lev)==mp.end()) mp[lev]=curr->data;                         // for top-view
        
        // for left-view and right-view
        if(curr->left) q.push({curr->left, lev+1});
        if(curr->right) q.push({curr->right, lev+1});
        
         // for bottom-view and top-view
         if(curr->left) q.push({curr->left, lev-1});
         if(curr->right) q.push({curr->right, lev+1});
    }
    
    for(auto it: mp) res.push_back(it.second);
    
    return res;
}
