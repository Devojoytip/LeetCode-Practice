// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution
{
    public:
    void preF(Node* r, Node*& pre, int k)
    {
        // Your code goes here
        if(!r) return;
        if(r->key==k) preF(r->left,pre,k);
        else if(r->key<k) 
        {
            pre=r;
            preF(r->right,pre,k);
        }
        else preF(r->left,pre,k);
    }
    
    void succF(Node* r, Node*& suc, int k)
    {
        // Your code goes here
        if(!r) return;
        if(r->key==k) succF(r->right,suc,k);
        else if(r->key>k) 
        {
            suc=r;
            succF(r->left,suc,k);
        }
        else succF(r->right,suc,k);
    }
    
    void findPreSuc(Node* r, Node*& pre, Node*& suc, int k)
    {
        // Your code goes here
        preF(r,pre,k);
        succF(r,suc,k);
    }
};
