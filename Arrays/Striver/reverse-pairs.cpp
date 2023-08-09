// https://leetcode.com/problems/reverse-pairs

#define ll long long

class Solution {
public:
    int merge(vector<int>& v, int s, int mid, int e)
    {
        int i=s, j=mid+1, count=0;

        while(i<=mid)
        {
            while(j<=e and v[i]>(ll)2*v[j]) j++;
            count+=j-mid-1;
            i++;
        }

        i=s, j=mid+1;
        vector<int> u;

        while(i<=mid and j<=e)
        {
            if(v[i]>v[j]) u.push_back(v[j]), j++;
            else u.push_back(v[i]), i++;
        }

        while(i<=mid) u.push_back(v[i]), i++;

        while(j<=e) u.push_back(v[j]), j++;

        for(i=s;i<=e;i++) v[i]=u[i-s];

        return count;
    }

    int mergeSort(vector<int>& v, int s, int e)
    {
        if(s>=e) return 0;

        int mid=(s+e)/2;
        ll left=mergeSort(v,s,mid);
        ll right=mergeSort(v,mid+1,e);
        ll mergeCost=merge(v,s,mid,e);

        return left+right+mergeCost;
    }

    int reversePairs(vector<int>& v) {

        return mergeSort(v, 0, v.size()-1);
    }
};
