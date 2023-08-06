// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& v, int t) {
        
        int n=v.size();
        int s=0,e=n-1;

        while(s<=e)
        {
            int mid=(s+e)/2;

            if(v[mid]==t) return mid;

            if(v[s]<=v[mid])
            {
                if(t>=v[s] and t<v[mid]) e=mid-1; // between start and mid
                else s=mid+1;
            }

            else 
            {
                if(t>v[mid] and t<=v[e]) s=mid+1; // between mid and end
                else e=mid-1;
            }
        }

        return -1;
    }
};
