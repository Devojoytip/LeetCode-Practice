// https://leetcode.com/problems/task-scheduler-ii

class Solution {
public:
    long long taskSchedulerII(vector<int>& t, int n) {
        
        unordered_map<int,long long int> mp;
        for(auto it:t) mp[it]=0;
        long long int time=0;

        for(auto it: t)
        {
            if(time>=mp[it]) // waiting time over for task of type it
            {
                time++;
                mp[it]=time+n;
            }
            else            // waiting time not over for task of type it
            {
                time=mp[it];
                time++;
                mp[it]=time+n;
            }
        }

        return time;
    }
};
