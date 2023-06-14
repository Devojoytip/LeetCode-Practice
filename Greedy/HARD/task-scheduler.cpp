// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        
        priority_queue<int> pq;
        vector<int> freq(26,0);

        for(auto it: t) freq[it-'A']++;

        for(auto it: freq)
        {
            if(it!=0) pq.push(it);
        }

        int time=0;
        while(!pq.empty())
        {
            vector<int> rem;
            int space=n+1;

            while(space>0 and !pq.empty())
            {
                int curr=pq.top();
                pq.pop();
                curr--;
                if(curr>0) rem.push_back(curr);
                time++;
                space--;
            }

            for(auto task:rem) pq.push(task);

            if(pq.empty()) break;

            time+=space;
        }

        return time;
    }
};
