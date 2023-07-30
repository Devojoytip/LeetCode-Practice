// https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<bits/stdc++.h>

vector<int> Solution::solve(vector<int> &v, vector<int> &u, int k) {
    
    int n=v.size();
    vector<int> res;
    
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push({v[i]+u[n-1],{i,n-1}});
    }
    
    while(pq.size() and k--)
    {
        int sum=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        
        res.push_back(sum);
        
        if(j>0) pq.push({v[i]+u[j-1],{i,j-1}});
    }
    
    return res;
}
