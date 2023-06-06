// https://leetcode.com/problems/rotate-array

class Solution {
public:

    void rotate(vector<int>& v,int s,int e)
    {
        while(s<=e)
        {
            swap(v[s],v[e]);
            s++;
            e--;
        }
    }
    
    void rotate(vector<int>& v, int k) {
        int n=v.size();
        k%=n;
        if(k==0) return;
        
        rotate(v,0,n-1);
        rotate(v,0,k-1);
        rotate(v,k,n-1);
    }
};
