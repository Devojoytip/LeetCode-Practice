// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    class cmp{
        public:
        bool operator()(pair<int,string> a, pair<int,string> b)
        {
            if(a.first==b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
       
       unordered_map<string,int> mp;

       priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

       vector<string> res;
       
       for(auto it:words) mp[it]++;
       
       for(auto it: mp) pq.push({it.second, it.first});

       while(k>0)
       {
           res.push_back(pq.top().second);
           pq.pop();
           k--;
       }

       return res;
    }
};
