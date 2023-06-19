// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ 


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* r) 
    {
        if(!r) return "null,";
        string s=to_string(r->val)+","+serialize(r->left)+serialize(r->right);
        return s;
    }

    TreeNode* makeTree(queue<string> & q)
    {
        if(q.empty()) return NULL;
        string s=q.front();
        q.pop();
        if(s=="null") return NULL;
        TreeNode* t=new TreeNode(stoi(s));
        t->left=makeTree(q);
        t->right=makeTree(q);
        return t;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        queue<string> q;
        string s="";
        
        for(auto ch:data)
        {
            if(ch==',') 
            {
                q.push(s);
                s="";
            }
            else s=s+ch;
        }

        return makeTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
