// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b)
    {
        if(a.second.second!=b.second.second) return a.second.second<b.second.second;
        if(a.second.first!=b.second.first) return a.second.first<b.second.first;
        return a.first<b.first;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        vector<pair<int,pair<int,int>>> v;
        int start=0,ans=0;
        
        for(int i=0;i<n;i++) v.push_back({i,{s[i],e[i]}});
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<n;i++)
        {
            if(start<v[i].second.first) 
            {
                start=v[i].second.second;
                ans++;
            }
        }
        
        return ans;
    }
};
