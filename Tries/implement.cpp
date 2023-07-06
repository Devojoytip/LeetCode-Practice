// https://leetcode.com/problems/implement-trie-prefix-tree

class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        flag = 0; // means no word
        for(int i=0;i<26;i++) links[i] = NULL;
    }
    
    bool containKey(char c)
    {
        return links[c-'a'] != NULL;
    }

    void put(char c)
    {
        links[c-'a']=new Node();
    }

    Node* get(char c)
    {
        return links[c-'a'];
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr=root;

        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            if(!curr->containKey(c))
            {
                curr->put(c);
            }

            curr=curr->get(c);
        }

        curr->flag=1;
    }
    
    bool search(string word) {
        Node *curr=root;

        for(int i=0;i<word.size();i++)
        {
            char c=word[i];

            if(!curr->containKey(c)) return 0;

            curr=curr->get(c);
        }

        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node *curr=root;

        for(int i=0;i<prefix.size();i++)
        {
            char c=prefix[i];

            if(!curr->containKey(c)) return 0;

            curr=curr->get(c);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
