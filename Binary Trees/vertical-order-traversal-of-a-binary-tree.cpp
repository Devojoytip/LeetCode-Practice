// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

class Solution {
public:
    void recur(TreeNode* r, int x, int y, map<int,map<int,multiset<int>>> &mp) {
        
        if(!r) return;

        mp[x][abs(y)].insert(r->val);

        if(r->left) recur(r->left, x-1, y+1, mp);

        if(r->right) recur(r->right, x+1, y+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* r) {
        
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> mp;
        
        recur(r,0,0,mp);

        for(auto i:mp)
        {
            vector<int>u;
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    u.push_back(k);
                }
            }
            res.push_back(u);
        }

        return res;
    }
};
