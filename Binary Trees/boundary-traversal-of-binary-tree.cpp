// https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

bool isLeaf(TreeNode<int> *r)
{
    return r and !r->left and !r->right;
}

void addLeft(TreeNode<int> *r, vector<int> &res)
{
    TreeNode<int>* t=r->left;
    
    while(t)
    {
        if(!isLeaf(t)) res.push_back(t->data);

        if(t->left) t=t->left;
        else t=t->right;
    }
}

void addRight(TreeNode<int> *r, vector<int> &res)
{
    if(!r or isLeaf(r)) return;
    
    vector<int> v;
    TreeNode<int>* t=r->right;
    
    while(t)
    {
        if(!isLeaf(t)) v.push_back(t->data);

        if(t->right) t=t->right;
        else t=t->left;
    }

    for(int i=v.size()-1;i>=0;i--) res.push_back(v[i]);
}

void addLeaves(TreeNode<int> *r, vector<int> &res)
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

vector<int> traverseBoundary(TreeNode<int> *r)
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
