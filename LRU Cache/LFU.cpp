// https://leetcode.com/problems/lfu-cache

class LFUCache {
public:
    map<int, list<int>> freq;
    map<int, list<int>::iterator> pos;
    map<int, pair<int,int>> nodes;
    int n,minFreq;

    LFUCache(int capacity) {
        this->n=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        
        if(nodes.find(key)==nodes.end()) return -1;

        int f=nodes[key].second+1;
        freq[f-1].erase(pos[key]);
        nodes[key].second=f;
        freq[f].push_back(key);
        pos[key]= -- freq[f].end();
        if(freq[minFreq].empty()) minFreq++;
        return nodes[key].first;
    }
    
    void put(int key, int value) {
        
        if(n<1) return;

        if(nodes.find(key)!=nodes.end())
        {
            nodes[key].first=value;
            int f=nodes[key].second+1;
            nodes[key].second=f;
            freq[f-1].erase(pos[key]);
            freq[f].push_back(key);
            pos[key]= -- freq[f].end();
            if(freq[minFreq].empty()) minFreq++;
            return;
        }

        if(nodes.size()==n)
        {
            int delKey=freq[minFreq].front();
            nodes.erase(delKey);
            pos.erase(delKey);
            freq[minFreq].pop_front();
        }
        
        nodes[key]={value,1};
        freq[1].push_back(key);
        pos[key]= --freq[1].end();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
