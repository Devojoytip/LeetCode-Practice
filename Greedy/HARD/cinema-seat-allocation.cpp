// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    void check(int seat,bool &left,bool &mid,bool &right)
    {
        if(seat==1 or seat==10) return;

        if(seat>=2 and seat<=5) left=0;
        if(seat>=4 and seat<=7) mid=0;
        if(seat>=6 and seat<=9) right=0; 

    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& v) 
    {
        map<int,vector<int>> mp;

        for(auto it:v) mp[it[0]].push_back(it[1]);

        int booked=mp.size();
        int empty=n-booked;
        int res=empty*2;

        for(auto it:mp)
        {
            int row=it.first;
            vector<int> u=it.second;

            bool left=1,mid=1,right=1;
            for(auto seat:u) check(seat,left,mid,right);

            if(left and right and mid) res+=2;
            else if(left or right or mid) res+=1;
        }

        return res;
    }
};
