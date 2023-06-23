// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {

        int n=v.size();
        int maxLen=(n%2==0) ? n-1 : n;
        int i=0,j=0;
        long long int sum=0,ans=0;

        for(int k=1;k<=maxLen;k+=2) // making window of all odd sizes from 1 to max odd size
        {
            i=0,j=0,sum=0;

            // Sliding window on window of size k
          
            while(j<v.size())
            {
                sum+=v[j];
                if(j-i+1==k)
                {
                    ans+=sum;
                    sum-=v[i];
                    i++;
                    j++;
                }
                else j++;
            }
        }

        return ans;
    }
};
