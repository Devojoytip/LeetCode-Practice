// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& v) {
        int n=v.size();
        if(n<=1) return 0;

        int i=0,j=1,sum=v[0];
        unordered_set<int> s;

        while(j<n)
        {
            sum+=v[j];
            if(s.find(sum)!=s.end()) return 1;
            s.insert(sum);
            sum-=v[i];
            i++;
            j++;
        }

        return 0;
    }
};
