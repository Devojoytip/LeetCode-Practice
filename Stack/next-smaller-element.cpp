// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &v) {
    
    stack<int>s;
    int n=v.size();
    vector<int> res;
    
    for(int i=0;i<n;i++)
    {
        while(s.size() and v[i]<=s.top()) s.pop();
        
        if(!s.size()) res.push_back(-1);
        else res.push_back(s.top());
        
        s.push(v[i]);
    }
    
    return res;
    
}
