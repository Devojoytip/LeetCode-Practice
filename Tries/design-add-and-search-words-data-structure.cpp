// https://leetcode.com/problems/design-add-and-search-words-data-structure

class Node{
    public:
    Node* links[26];
    bool flag;

    Node()
    {
        flag=0;
        for(int i=0;i<26;i++) links[i]=NULL;
    }

    bool containsKey(char c)
    {
        return links[c-'a'] != NULL;
    }

    void put(char c)
    {
        links[c-'a'] = new Node();
    }

    Node* get(char c)
    {
        return links[c-'a'];
    }
};

class WordDictionary {
public:
    Node *root;

    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* curr=root;

        for(int i=0;i<word.size();i++)
        {
            char c=word[i];

            if(!curr->containsKey(c)) curr->put(c);

            curr=curr->get(c);
        }

        curr->flag=1;
    }
    
    bool helper(Node* node, string word, int idx) 
    {
        if(idx==word.size() and node->flag) return true;
        if(idx==word.size() and !node->flag) return false;

        Node* curr=node;

        char c=word[idx];

        if(c=='.') 
        {
            for(int i=0;i<26;i++) 
            {
                if(curr->links[i]) 
                {
                    int ans=helper(curr->links[i], word, idx+1);
                    if(ans) return 1;
                }
            }
            return 0;
        }

        else
        {
            if(!curr->containsKey(c)) return 0;
            
            return helper(curr->links[c-'a'], word, idx+1);
        }
    }

    bool search(string word) {
        Node* temp=root;
        return helper(temp,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
