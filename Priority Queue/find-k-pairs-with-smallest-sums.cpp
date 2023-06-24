// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {

        vector<vector<int>> res;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        for(int i=0;i<v1.size();i++) pq.push({v1[i]+v2[0],{i,0}});

        while(!pq.empty() and k--)
        {
            int i=pq.top().second.first, j=pq.top().second.second;
            pq.pop();
            res.push_back({v1[i],v2[j]});
            if(j+1!=v2.size()) pq.push({v1[i]+v2[j+1],{i,j+1}});
        }

        return res;
    }
};
