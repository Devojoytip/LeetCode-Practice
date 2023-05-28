/*

Aditya Verma -  since it has only positives it will work
4 DIFF : 
1. k = total - x 
2. ans = n - maxLength
3. if(k==0) return n -> as we have to take all ele as x=total
4. if(k<0) return -1 -> as it is not possible

*/

class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        map<int,int> mp;
        int ans=-1,sum=0,i=0,j=0,total=0,k,n=v.size();
        for(auto it:v) total+=it;
        k=total-x;
        if(k==0) return n;
        if(k<0) return -1;

        while(j<n)
        {
            sum+=v[j];
            if(sum<k) j++;
            else if(sum==k) 
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                while(sum>k)
                {
                    sum-=v[i];
                    i++;
                }
                if(sum==k) ans=max(ans,j-i+1);
                j++;
            }
            
        }

        return (ans==-1) ? -1 : n-ans;  
    }
};
