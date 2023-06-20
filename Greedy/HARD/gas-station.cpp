// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int ans=0,curr=0,n=gas.size(),totalGas=0,totalCost=0;

        for(int i=0;i<n;i++)
        {
            totalGas+=gas[i];
            totalCost+=cost[i];
        }

        if(totalGas<totalCost) return -1;

        for(int i=0;i<n;i++)
        {
            curr+=gas[i]-cost[i];
            if(curr<0)
            {
                curr=0;
                ans=i+1;
            }
        }

        return ans;
    }
};
