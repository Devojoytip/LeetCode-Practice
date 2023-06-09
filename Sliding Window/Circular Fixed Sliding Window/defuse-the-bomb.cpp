// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& v, int k) {
        
        int n(v.size()),i(0),j(0),sum(0);
        vector<int> res(n,0);

        if(k==0) return res;
        else if(k>0)
        {
            while(j!=k)
            {
                sum+=v[j];
                j++;
            }
            j=k-1;
            res[n-1]=sum;

            while(i!=n-1)
            {
                sum-=v[i];
                i++;
                j=(j+1)%n;
                sum+=v[j];
                res[i-1]=sum;
            }
        }
        else
        {
            sum=0;
            j=0;
            i=0;
            k=abs(k);
            while(j!=k)
            {
                sum+=v[j];
                j++;
            }
            j=k-1;
            res[j+1]=sum;
            while(i!=n-1)
            {
                sum-=v[i];
                i++;
                j=(j+1)%n;
                sum+=v[j];
                res[(j+1)%n]=sum;
            }
        }
        return res;

    }
};
