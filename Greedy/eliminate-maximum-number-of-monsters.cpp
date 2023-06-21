// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int n=dist.size();
        vector<double> time(n,0);

        // find time taken by each monster to reach the city
        for(int i=0;i<n;i++) time[i]=(double) dist[i]/speed[i];
        sort(time.begin(),time.end());

        int currTime=0;

        for(auto it: time)
        {
            if(it>currTime) 
            {
                currTime++;
                continue;
            }
            else break;
        }

        return currTime;
    }
};
