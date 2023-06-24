// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    vector<string> v;
    int ptr;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        ptr=0;
    }
    
    void visit(string url) {
        while(ptr!=v.size()-1) v.pop_back();
        v.push_back(url);
        ptr++;
        return;
    }
    
    string back(int steps) {
        int cnt=0;
        while(ptr>=1)
        {
            cnt++;
            ptr--;
            if(cnt==steps) 
            {               
                return v[ptr];
            }
        }
        return v[ptr];
    }
    
    string forward(int steps) {
        int cnt=0;
        while(ptr<v.size()-1)
        {
            cnt++;
            ptr++;
            if(cnt==steps) 
            {               
                return v[ptr];
            }
        }
        return v[ptr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
