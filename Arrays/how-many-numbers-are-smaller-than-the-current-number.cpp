// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

/*

Complexity
Time complexity: O(n)
Space complexity: O(n)

Store freq of each no in an array which can hold all v[i] from 1 to N
freq[i] += freq[i-1] to store no of nos <= i
thus res[i] = no of nos < v[i] = freq[v[i]-1]

*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& v) {

        int n = v.size();
        vector<int> freq(101,0);
        vector<int> res(n,0);

        for(int i=0;i<n;i++) freq[v[i]]++;

        for(int i=1;i<101;i++) freq[i]+=freq[i-1];

        for(int i=0;i<n;i++) 
        {
            if(v[i]==0) res[i]=0;
            else res[i]=freq[v[i]-1];
        }

        return res;
    }
};
