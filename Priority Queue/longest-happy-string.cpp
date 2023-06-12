// https://leetcode.com/problems/longest-happy-string

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        
        while(pq.size()) {
            int x = pq.top().first;
            char chx = pq.top().second;
            pq.pop();

            if(ans.size() >= 2) { 
                int n = ans.size();
                if(ans[n - 1] == ans[n - 2] && ans[n - 1] == chx) {
                    if(!pq.size()) return ans;
                    
                    int y = pq.top().first;
                    char chy = pq.top().second;
                    pq.pop();
                    ans += chy;
                    y--;
                    if(y > 0) pq.push({y, chy});
                }
            }
            ans += chx;
            x--;
            if(x > 0) pq.push({x, chx});
        }
        return ans;
    }
};
