// https://leetcode.com/problems/remove-comments

class Solution {
public:
    vector<string> removeComments(vector<string>& v) {
        
        vector<string> res;

        string prev="",curr="";

        for(auto s:v)
        {
            int i=0,n=s.size();
            while(i<n)
            {
                if(prev=="/*")
                {
                    if(s[i]=='*' and i+1<n and s[i+1]=='/')
                    {
                        prev="";
                        i+=2;   
                    }
                    else i++;
                }
                else if(s[i]=='/' and i+1<n and s[i+1]=='/')
                {
                    break;
                }
                else if(s[i]=='/' and i+1<n and s[i+1]=='*')
                {
                    prev="/*";
                    i+=2;
                }
                else
                {
                    curr+=s[i];
                    i++;
                }
            }

            if(prev=="")
            {
                if(curr!="") 
                {
                    res.push_back(curr);
                    prev="";
                    curr="";
                }                
            }
        }

        return res;
    }
};
