// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        
        priority_queue<pair<int, int>> pq;
        int i=0;
        
        for (auto point : v) 
        {
            int x1 = point[0], y1 = point[1];
            int dis= -(x1*x1 + y1*y1);
            pq.push({dis, i});
            i++;
        }

        vector<vector<int>> res;

        while (k--) 
        {
            int idx=pq.top().second;
            res.push_back(v[idx]); 
            pq.pop();
        }

        return res;
    }
};
