// https://leetcode.com/problems/majority-element

// Moore's election algo

class Solution {
public:
    int majorityElement(vector<int>& v) {
        
        int i=0,cnt=0,ele=0;

        for(int i=0;i<v.size();i++)
        {
            if(cnt==0)
            {
                cnt=1;
                ele=v[i];
            }
            else if(ele==v[i]) cnt++;
            else cnt--;
        }
        
        int temp=0;
        for(auto it:v) 
        {
            if(it==ele) temp++;
        }

        if(temp>v.size()/2) return ele;
        return -1;
    }
};
