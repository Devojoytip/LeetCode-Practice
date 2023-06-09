// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0,cnt=1;

        for(int j=1;j<v.size();j++)
        {
            if(v[i]!=v[j]) 
            {
                i++;
                v[i]=v[j];
                cnt=1;
            }
            else
            {
                if(cnt<2) 
                {
                    i++;
                    v[i]=v[i-1];
                    cnt++;
                }
            }
        }

        return i+1;
    }
};
