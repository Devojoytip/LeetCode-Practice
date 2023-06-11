// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void recur(vector<int> v,int idx, int sum, int n,vector<int> &res)
    {
        if(idx>=n) 
        {
            res.push_back(sum);
            return;
        }
        
        recur(v,idx+1,sum,n,res);
        
        sum+=v[idx];
        recur(v,idx+1,sum,n,res);
    }
    
    vector<int> subsetSums(vector<int> v, int n)
    {
        // Write Your Code here
        vector<int> res;
        recur(v,0,0,n,res);
        
        return res;
    }
};
