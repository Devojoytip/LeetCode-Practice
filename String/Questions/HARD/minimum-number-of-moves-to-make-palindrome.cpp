// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome

class Solution {
public:
    int minMovesToMakePalindrome(string st) {
        
        int s=0, e=st.size()-1, cnt=0;

        while(s<e)
        {
            if(st[s]!=st[e])
            {
                int l=s, r=e;

                while(st[r]!=st[l]) r--;

                if(l==r) 
                {
                    swap(st[l],st[l+1]);
                    cnt++;
                    continue;
                }

                else 
                {
                    while(r!=e) 
                    {
                        swap(st[r], st[r+1]);
                        cnt++;
                        r++;
                    }
                }
            }

            s++;
            e--;
        }

        return cnt;
    }
};
