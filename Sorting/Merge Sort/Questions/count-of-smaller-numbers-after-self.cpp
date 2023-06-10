/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self

Same as reverse pairs

Diff:
We need to store the indexes of the nos as well as we need to calc individual count for each index and sorting changes the order

*/

#define LL long long
class Solution {
public:
    void Merge(vector<int> &res, vector<pair<int, int>>& v,int low,int mid,int high) {

        int cnt=0,i=low,j=mid+1;
        for(;i<=mid;i++)
        {
            while(j<=high and v[i].first > v[j].first)
            {
                j++;
            }
            cnt=j-(mid+1);
            res[v[i].second]+=cnt;
        }

        vector<pair<int, int>> temp;

        i=low,j=mid+1;

        while(i<=mid and j<=high)
        {
            if(v[i].first<=v[j].first) 
            {
                temp.push_back(v[i]);
                i++;
            }
            else
            {
                temp.push_back(v[j]);
                j++;
            }
        }

        while(i<=mid)
        {
            temp.push_back(v[i]);
            i++;
        }

        while(j<=high)
        {
            temp.push_back(v[j]);
            j++;
        }

        i=low;
        for(;i<=high;i++)
        {
            v[i]=temp[i-low];
        }

        return;
    }

    void MergeSort(vector<int> &res, vector<pair<int, int>>& v, int low, int high)
    {
        if (low >= high) return;
        int mid = (low + high) / 2;
        MergeSort(res, v, low, mid);
        MergeSort(res, v, mid + 1, high);
        Merge(res, v, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n,0);
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++) v.push_back({nums[i], i});

        MergeSort(res, v, 0, n - 1); 

        return res;
    }
};
