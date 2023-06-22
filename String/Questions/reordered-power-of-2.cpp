// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string str = to_string(n);
        sort(str.begin(),str.end());
        long long int num;
        int counter=0;
        
        while(true)
        {
            num = pow(2,counter++);
            
            string temp = to_string(num);
            
            if(temp.length()>str.length()) return false; 
            
            sort(temp.begin(),temp.end());
                
            if(str == temp) return true;
            
        }     
        return false;   
    }
};
