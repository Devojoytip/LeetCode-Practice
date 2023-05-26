class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) 
    {
        int i=0,j=0;
        long long int ans=0,sum=0;
        map<int,int>mp;

        while(i<v.size())
        {
            int num=v[i];
            if(mp.count(num)==0) sum+=num;
            mp[num]++;

            if(mp.size()==k) ans=max(ans,sum);

            if(i+1>=k)
            {
                int first_idx=i+1-k;
                int firstNum=v[first_idx];
                mp[firstNum]--;
                
                if(mp[firstNum]==0) 
                {
                    sum-=firstNum; // since we are adding it only once
                    mp.erase(firstNum);
                }
            }

            i++;
        }

        return ans;
    }
};
