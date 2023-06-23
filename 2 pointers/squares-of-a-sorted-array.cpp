// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {

        vector<int> res(v.size(),0);
        int i=v.size()-1;
        int l=0,r=v.size()-1;

        while(i>=0)
        {
            int leftP=pow(v[l],2), rightP=pow(v[r],2);
            if(leftP>rightP) 
            {
                res[i]=leftP;
                l++;
            }
            else 
            {
                res[i]=rightP;
                r--;
            }
            i--;
        }

        return res;
    }
};
