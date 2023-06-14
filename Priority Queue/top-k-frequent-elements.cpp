// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        
        unordered_map<int,int> mp;
        vector<int> res;

        for(auto it:v) mp[it]++;

        priority_queue<pair<int,int>> pq;
        for(auto it:mp) pq.push({it.second,it.first});

        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
