/*

https://leetcode.com/problems/partition-labels

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> freq;
        map<char,int> curr;
        vector<int> res;

        for(int i=0;i<s.size();i++) freq[s[i]]++;

        int i=0,j=0,target=0;

        while(j<s.size())
        {
            char ch=s[j];
            if(curr.find(ch)==curr.end())
            {
                target+=freq[ch];
                target--;
                if(target==0) 
                {
                    res.push_back(j-i+1);
                    i=j+1;
                    j++;
                    target=0;
                }
                else 
                {
                    j++;
                    curr[ch]=1;
                }                
            }
            else
            {
                target--;
                if(target==0) 
                {
                    res.push_back(j-i+1);
                    i=j+1;
                    j++;
                    target=0;
                }
                else j++;    
            }
            
        }

        return res;

    }
};
