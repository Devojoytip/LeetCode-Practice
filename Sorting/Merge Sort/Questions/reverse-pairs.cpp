// https://leetcode.com/problems/reverse-pairs

#define LL long long
class Solution {
public:
    int Merge(vector<int>& v,int low,int mid,int high) {

        int total=0,i=low,j=mid+1;
        for(;i<=mid;i++)
        {
            while(j<=high and v[i]>2LL *v[j])
            {
                j++;
            }
            total+=j-(mid+1);
        }

        vector<int> temp;

        i=low,j=mid+1;

        while(i<=mid and j<=high)
        {
            if(v[i]<=v[j]) 
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

        return total;
    }

    int MergeSort(vector<int>& v, int low, int high)
    {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int inv = MergeSort(v, low, mid);
        inv += MergeSort(v, mid + 1, high);
        inv += Merge(v, low, mid, high);
        return inv; 
    }

    int reversePairs(vector<int>& v) {
        return MergeSort(v, 0, v.size() - 1); 
    }
};
