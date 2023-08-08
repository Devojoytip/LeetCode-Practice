class Solution{
    public:
    
    vector<int> insert(vector<int>v, int ele)
    {
        if(v.size()==0 or v.back()<=ele)     
        {
            v.push_back(ele);
            return v;
        }
        
        int last=v[v.size()-1];
        v.pop_back();
        v=insert(v,ele);
        v.push_back(last);
        
        return v;
    }
    
    vector<int> sortArr(vector<int>v, int n)
    {
        //complete the function here
        if(v.size()<=1) return v;
        
        int last=v[v.size()-1];
        v.pop_back();
        v=sortArr(v,n);
        v=insert(v,last);
        
        return v;
    }
};
