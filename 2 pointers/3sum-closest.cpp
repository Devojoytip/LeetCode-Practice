/*

https://leetcode.com/problems/3sum-closest/

Check if the absolute difference between the sum and the target is smaller than the absolute difference between closest and the target. 
If so, update closest to the current sum.
Update low and high according to value of sum.

*/

class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {

        int n=v.size(),ans;
        
        sort(v.begin(),v.end());

        if(n<3) return 0;
        
        ans = v[0]+v[1]+v[2];
        

        for(int i=0;i<n-2;i++)
        {
            int low=i+1,high=n-1,sum=0;

            while(low<high)
            {
                sum=v[i]+v[low]+v[high];
                
                if(target==sum) return sum;

                if(abs(target-sum)<abs(target-ans)) ans=sum;

                if(sum<target) low++;
                
                else high--;
            }
            
        }

        return ans;
    }
};
