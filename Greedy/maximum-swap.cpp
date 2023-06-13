// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int n) {

        vector<int>v;

        while(n>0)
        {
            v.push_back(n%10);
            n/=10;
        }

        int m=v.size();
        vector<int>rep(m,-1);
        int maxi=0;

        for(int idx=1;idx<m;idx++)
        {
            if(v[idx]<v[maxi]) rep[idx]=maxi;
            else if(v[idx]>v[maxi])
            {
                maxi=idx;
            }
        }

        for(int i=m-1;i>=0;i--)
        {
            if(rep[i]!=-1) 
            {
                swap(v[i],v[rep[i]]);
                break;
            }
        }

        int mul=1;
        int num=0;
        for(int i=0;i<m;i++){
            num+=(v[i]*mul);
            mul*=10;
        }

        return num;
    }
};
