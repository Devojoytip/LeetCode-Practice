/*

https://leetcode.com/problems/boats-to-save-people

sort the arr
we use 2 pointers to see if sum of lowest & highest values <= t
if yes then we can carry both the persons using 1 boat nad update i++,j--
else we have to carry person with higher boat using 1 boat update j--

*/

class Solution {
public:
    int numRescueBoats(vector<int>& v, int t) {

        sort(v.begin(),v.end());

        int i=0,j=v.size()-1,cnt=0;

        while(i<=j)
        {
            if(i==j)
            {
                if(v[i]<=t) cnt++;
                i++;
            }
            else
            {
                if(v[i]+v[j]<=t) 
                {
                    cnt++;
                    i++;
                    j--;
                }
                else 
                {
                    cnt++;
                    j--;
                }
            }
        }

        return cnt;
    }
};
