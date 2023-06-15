// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string sol(string n1, string n2) {

        if(n1=="0" or n2=="0") return "0";

        int m=n1.size(),k=n2.size();
        vector<int>v (m+k,0);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=k-1;j>=0;j--)
            {
                v[i+j+1] += (n1[i]-'0')*(n2[j]-'0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1] = v[i+j+1] % 10;
            }
        }

        int i=0;
        for(i=0;i<v.size();i++)
        {
            if(v[i]!=0) break;
        }

        string res="";

        while(i<v.size()) 
        {
            res += to_string(v[i]);
            i++;
        }

        return res;
    }

    string multiply(string n1, string n2) {

        return sol(n1,n2);
    }
};
