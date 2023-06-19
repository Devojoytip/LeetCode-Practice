// https://leetcode.com/problems/reverse-string-ii

class Solution {
public:
    void rev(string &s, int i, int k)
    {
        int j=i+k-1;
        if(j>=s.size()) j=s.size()-1;
        while(i<=j) swap(s[i++],s[j--]);
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k) rev(s,i,k);
        return s;
    }
};
