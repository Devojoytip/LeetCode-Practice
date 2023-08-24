// https://leetcode.com/problems/lru-cache
/*

Doubly linked list and map

*/

class LRUCache {
public:
    class Node
    {
        public:
        Node *prev, *next;
        int key, val;

        Node(int key, int val)
        {
            this->key=key;
            this->val=val;
            this->prev=NULL;
            this->next=NULL;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int capacity;
    map<int, Node*> mp;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* temp)
    {
        Node* nextNode=head->next;
        head->next=temp;
        temp->next=nextNode;
        temp->prev=head;
        nextNode->prev=temp;
        mp[temp->key]=temp;
    }

    void deleteNode(Node* temp)
    {
        Node* prevNode=temp->prev;
        Node* nextNode=temp->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        mp.erase(temp->key);
        delete temp;
    }

    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        
        Node* temp=mp[key];
        int val=temp->val;

        deleteNode(temp);
        addNode(new Node(key, val));
        
        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()) deleteNode(mp[key]);
        if(mp.size()==capacity) deleteNode(tail->prev);
        addNode(new Node(key, value));
    }
};
