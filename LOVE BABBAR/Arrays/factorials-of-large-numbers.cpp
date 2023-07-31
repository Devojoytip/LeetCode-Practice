// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

class Solution {
public:
    vector<int> factorial(int n)
    {
        // code here
        vector<int> res;
        int k=1;
        int carry=0;
        
        while(k<=n)
        {
            if(res.empty())
            {
                res.push_back(1);
                continue;
            }
            
            for(int i=0;i<res.size();i++)
            {
                int num=(res[i]*k)+carry;
                res[i]=num%10;
                carry=num/10;
            }
            
            while(carry)
            {
                res.push_back(carry%10);
                carry/=10;
            }
            
            k++;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
