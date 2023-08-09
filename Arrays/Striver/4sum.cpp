// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        
        vector<vector<int>> res;
        int n=v.size();
        sort(v.begin(), v.end());

        for(int i=0;i<n-3;i++)
        {

            if(i>0 and v[i]==v[i-1]) continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 and v[j]==v[j-1]) continue;

                int s=j+1, e=n-1;

                while(s<e)
                {
                    long long int sum=v[i];
                    sum+=v[j];
                    sum+=v[s];
                    sum+=v[e];

                    if(sum==t)
                    {
                        res.push_back({v[i], v[j], v[s], v[e]});
                        s++;
                        e--;
                        while(s<e and v[s]==v[s-1]) s++;
                        while(e>s and v[e]==v[e+1]) e--;
                    }

                    else if(sum>t) e--;

                    else s++;
                }
            }
        }

        return res;
    }
};
