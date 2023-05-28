/*
https://leetcode.com/problems/remove-all-occurrences-of-a-substring

Sliding window

DIFF:

1. k = size of part
2. j++ till we get string of size k
3. when match found erase it & intializa i=0,j=0
4. else i++, j++ to maintain length = k

*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0,j=0,k=part.size();
        vector<int> v(26,0);
        string temp=s;

        while(j<temp.size())
        {
            if(j-i+1<k) j++;
            else if(j-i+1==k)
            {
                if(temp.substr(i,k)==part)
                {
                    temp.erase(i,k);
                    i=0;
                    j=0;
                }
                else 
                {
                    i++;j++;
                }
            }
        }

        return temp;
    }
};
