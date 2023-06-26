// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int num) {
        
        string s=to_string(num);
        int n=s.size();
        int deflection=n-1;

        while(deflection>0)
        {
            if(s[deflection-1]<s[deflection]) break;
            deflection--;
        }

        if(deflection==0) return -1;

        int left=deflection-1;
        int right=n-1;

        while(left<=right)
        {
            if(s[left]<s[right]) break;
            right--;
        }

        swap(s[left],s[right]);
        sort(s.begin()+left+1,s.end());

        long long ans=stoll(s);

        if(ans > pow(2,31)-1) return -1;

        return ans;
    }
};
