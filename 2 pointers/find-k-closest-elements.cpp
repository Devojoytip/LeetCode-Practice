// https://leetcode.com/problems/find-k-closest-elements


class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int i=0,j=v.size()-1;
        vector<int> res;

        while(i<=j)
        {
            if(j-i+1==k)
            {
                for(int idx=i;idx<=j;idx++) res.push_back(v[idx]);
                break;
            }
            else
            {
                if(abs(v[i]-x)>abs(v[j]-x)) i++;
                else j--;
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};
