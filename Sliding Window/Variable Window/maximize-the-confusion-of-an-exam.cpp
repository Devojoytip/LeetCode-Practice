// https://leetcode.com/problems/maximize-the-confusion-of-an-exam

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        int n=s.size(), i=0, j=0, cnt=0, tr=0, fa=0, ans=0;

        while(j<n)
        {
            char c=s[j];
            tr += (c=='T');
            fa += (c=='F');

            if(tr>k and fa>k)
            {
                if(s[i]=='T') tr--;
                else fa--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};
