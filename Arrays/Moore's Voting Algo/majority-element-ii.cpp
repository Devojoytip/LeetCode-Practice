// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        
        int n=v.size();

        int ele_1=INT_MIN;
        int ele_2=INT_MIN;

        int cnt_1=0;
        int cnt_2=0;

        for(int i=0;i<n;i++)
        {
            if(cnt_1==0 and v[i]!=ele_2)
            {
                cnt_1++;
                ele_1=v[i];
            }
            else if(cnt_2==0 and v[i]!=ele_1)
            {
                cnt_2++;
                ele_2=v[i];
            }
            else if(v[i]==ele_1) cnt_1++;
            else if(v[i]==ele_2) cnt_2++;
            else cnt_1-- , cnt_2--;
        }

        cnt_1 = 0, cnt_2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == ele_1) cnt_1++;
            if (v[i] == ele_2) cnt_2++;
        }

        vector<int> res;

        int mini = int(n / 3) + 1;
        if (cnt_1 >= mini) res.push_back(ele_1);
        if (cnt_2 >= mini) res.push_back(ele_2);

        return res;

    }
};
