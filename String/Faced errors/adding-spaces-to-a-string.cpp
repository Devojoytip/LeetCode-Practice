// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int i=0,j=0;
        string res="";
        
        for(;i<s.size();i++)
        {
            if(j<spaces.size() and spaces[j]==i)
            {
                // res+=" "+s[i]; gives ERROR: index 72 out of bounds for type 'const char [2]' (solution.cpp)  it's because the addition operator (+) has higher precedence than the concatenation operator (+=). As a result, " " and s[i] are being treated as pointers to characters instead of strings.
                res+=" ";
                res+=s[i];
                j++;
            }
            else res+=s[i];
        }

        return res;
    }
};
