// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &v, int k) {
    
    int n=v.size(),i=0,j=0,cnt=0;
    unordered_map<int,int> mp;
    vector<int> res;
    
    while(j<n)
    {
        mp[v[j]]++;
        if(mp[v[j]]==1) cnt++;
        
        if(j-i+1==k)
        {
            res.push_back(mp.size());
            mp[v[i]]--;
            if(mp[v[i]]==0) mp.erase(v[i]);
            i++;
        }
        j++;
    }
    
    return res;
}
