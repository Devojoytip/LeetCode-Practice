// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int,int>>s;

    StockSpanner() {
        
    }
    
    int next(int p) {

        if(!s.size()) 
        {
            s.push({p,1});
            return 1;
        }

        int cnt=1;
        while(s.size() and s.top().first<=p) 
        {
            cnt+=s.top().second;
            s.pop();
        }
        s.push({p,cnt});

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
