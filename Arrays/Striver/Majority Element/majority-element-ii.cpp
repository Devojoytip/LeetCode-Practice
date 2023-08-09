// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        
        vector<int> res;

        int n=v.size(), c1=0, c2=0, e1=INT_MIN, e2=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int num=v[i];

            if(c1==0 and num!=e2) c1++, e1=num;

            else if(c2==0 and num!=e1) c2++, e2=num;

            else if(num==e1) c1++;

            else if(num==e2) c2++;

            else c1--,c2--;
        }

        int f1=0, f2=0;

        for(int i=0;i<n;i++)
        {
            if(v[i]==e1) f1++;
            if(v[i]==e2) f2++;
        }

        int m=int(n/3)+1;

        if(f1>=m) res.push_back(e1);
        if(f2>=m) res.push_back(e2);

        return res;
    }
};
