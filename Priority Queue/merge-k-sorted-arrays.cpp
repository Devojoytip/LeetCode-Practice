// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>>&v, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;

    for(auto u: v)
    {
        for(auto i: u) pq.push(i);
    }

    while(pq.size())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}
