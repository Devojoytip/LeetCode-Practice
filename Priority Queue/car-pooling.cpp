// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int capacity) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<v.size();++i)
        {
            pq.push({v[i][1],v[i][0]});
            pq.push({v[i][2],-v[i][0]});
        }
        
        int onboard =0;
        
        while(!pq.empty())
        {
            onboard = onboard + pq.top().second;
            pq.pop();
            if(onboard>capacity) return 0;
        }
        
        return 1;
    }
};
