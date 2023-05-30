/*

All sub array in the array of size n is: n∗(n+1)/2
Sub arrays with size 2 and 1 in array of size K: n+(n−1)
Hence, we have the formula to find a valid size sub array is: n^2−3*n+2/2

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        
        if(v.size()<3) return 0;
        int i=0,j=0,n=v.size(),diff=v[1]-v[0],cnt=0;

        while(j+1<n)
        {
            if(diff!=v[j+1]-v[j]) 
            {
                int len=j-i+1;
                if(len>=3) cnt+=(pow(len,2)-3*len+2)/2;
                i=j;
                j++;
                diff=v[j]-v[i];
                
            }

            else j++;

        }
        int len=j-i+1;
        if(len>=3) cnt+=(pow(len,2)-3*len+2)/2;
        return cnt;
    }
};
