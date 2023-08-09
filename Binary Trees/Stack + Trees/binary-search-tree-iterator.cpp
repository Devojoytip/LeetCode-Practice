// https://leetcode.com/problems/binary-search-tree-iterator

// Use a stack to store all node values .
// Order - reverse of Inorder ie Right Root Left so left values at top

class BSTIterator {
public:
    stack<int> s;

    void ReverseInorder(TreeNode* r)
    {
        if(!r) return;

        ReverseInorder(r->right);
        s.push(r->val);
        ReverseInorder(r->left);
    }

    BSTIterator(TreeNode* r) {
        ReverseInorder(r);
    }
    
    int next() {

        int ans=s.top();
        s.pop();

        return ans; 
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
