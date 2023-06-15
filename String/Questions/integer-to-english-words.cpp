// https://leetcode.com/problems/integer-to-english-words

class Solution {
public:
        string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        string thousands[4] = {"", " Thousand", " Million", " Billion"};

    string recur(int n) {
        
        if(n<20) return ones[n];

        if(n<100) return tens[n/10] + recur(n%10);

        if(n<1000) return recur(n/100) + " Hundred" + recur(n%100);

        else
        {
            for(int i=3;i>=0;i--)
            {
                int temp=pow(1000,i);
                if(n>=temp)
                {
                    return recur(n/temp) + thousands[i]+ recur(n%temp);
                } 
            }
        }

        return "";
    }

    string numberToWords(int n) {
        
        if(n==0) return "Zero";

        return recur(n).substr(1); // trims extra space from left
    }
};
