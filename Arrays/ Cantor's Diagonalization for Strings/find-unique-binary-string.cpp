/*
  
  https://leetcode.com/problems/find-unique-binary-string
  
  Cantor's Diagonalization
  
  Since we are given that number of bits in the number is equal to number of elements.
  What we can do is we create a binary string which differs from first binary at 1st position, 
  second binary at 2nd position, third binary at 3rd position,...and so on.
  
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& v) {
        
        string res="";
        for(int i=0;i<v.size();i++) 
        {
            res+= (v[i][i]=='1') ? '0' : '1';
        }

        return res;
    }
};
