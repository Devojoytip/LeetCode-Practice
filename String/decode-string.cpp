// https://leetcode.com/problems/decode-string

class Solution {
public:
    //Function to help repeat the substring a number of times
    string repeat(string str,int times){
        string result="";
        for(int i=0;i<times;i++) result += str;
        return result;
    }

    string decodeString(string s) {
        int i=0;
        while(i<s.size())
        {
            if(s[i]!=']')
            {
                i++;
                continue;
            }
            int j=i;

            while(s[j]!='[') j--;

            string curr= s.substr(j+1,i-j-1);

            int k=j-1;
            j--;
            while(k>=0 and isdigit(s[k])) k--;
            k++;
            int num=stoi(s.substr(k,j-k+1));

            s.replace(k,i-k+1,repeat(curr,num));

            i=k+curr.size()*num;
        }
        return s;
    }
};
