/*

https://leetcode.com/problems/number-of-arithmetic-triplets

*/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {

        int count=0;

        for(int i=0;i<nums.size()-2;i++)
        {
            int start = i+1,end = nums.size()-1;

            while(start < end)
            {

                if(nums[start]-nums[i] == diff && nums[end]-nums[start] == diff)
                {
                    count++;
                    break;
                }

                if(nums[start]-nums[i] < diff) start++;

                else if(nums[start]-nums[i] == diff && nums[end]-nums[start]>diff) end--;

                else break;
            }
        }
        
        return count;
    }
};
