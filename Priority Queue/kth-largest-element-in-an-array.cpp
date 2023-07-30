// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        
        priority_queue<int> pq;

        for(auto i: v) pq.push(i);

        while(k>1) 
        {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};
