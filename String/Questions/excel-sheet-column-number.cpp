// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(char c : s)
        {
            int d = c - 'A' + 1;
            res = res * 26 + d;
        }
        return res;
    }
};
