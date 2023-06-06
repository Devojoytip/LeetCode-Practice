// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void wiggleSort(vector<int>& v) {

        priority_queue<int> pq(v.begin(),v.end());
        int n=v.size();

        for(int i=1;i<n;i+=2)
        {
            v[i]=pq.top();
            pq.pop();
        }

        for(int i=0;i<n;i+=2)
        {
            v[i]=pq.top();
            pq.pop();
        }

    }
};
