// Start with mid ele as root and recursively build its left child and right child
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

class Solution {
public:
    TreeNode* recur(TreeNode* r, vector<int> &v,int s,int e) {

        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        r = new TreeNode(v[mid]);
        r->left=recur(r->left,v,s,mid-1);
        r->right=recur(r->right,v,mid+1,e);
        return r;
    }
    TreeNode* sortedListToBST(ListNode* h) {

        vector<int> v;
        ListNode* t=h;
        while(t)
        {
            v.push_back(t->val);
            t=t->next;
        }
        TreeNode* r = NULL;
        return recur(r, v,0,v.size()-1);
    }
};
