// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),[](const vector<int>& a,const vector<int>& b)
        {
            if(a[1]==b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int date=0;
        priority_queue<int> pq;

        for(auto it:v)
        {
            date+=it[0];
            pq.push(it[0]);
            if(date>it[1])
            {
                int highest=pq.top();
                pq.pop();
                date-=highest;
            }
        }

        return pq.size();
    }
};
