// https://leetcode.com/problems/lru-cache
/*

Doubly linked list and map

*/
class LRUCache {
public:
    class Node
    {
        public:
        int val;
        int key;
        Node*next;
        Node*prev;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };
    
    int n;
    map<int,Node*> mp;
    Node*head=new Node(0,0);
    Node*tail=new Node(0,0);

    LRUCache(int capacity) {
        n=capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* root)
    {
        mp[root->key]=root;
        Node* temp=head->next;
        head->next=root;
        root->next=temp;
        temp->prev=root;
        root->prev=head;
    }

    void deleteNode(Node* root)
    {
        mp.erase(root->key);
        Node* r1 = root->prev;
        Node* r2 = root->next;
        r1->next = r2;
        r2->prev = r1; 
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        Node* root = mp[key];
        deleteNode(root);
        addNode(root);
        return root->val;
    }
    
    void put(int key, int value) {
        Node* root = new Node(key,value);
        if(mp.count(key)!=0) deleteNode(mp[key]); // update the LRU ie the node becomes most recent so delete it and again add new
        if(mp.size()==n) deleteNode(tail->prev);  // cache is full so del least used ie tail's prev
        addNode(root); 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
