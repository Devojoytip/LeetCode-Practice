// https://www.interviewbit.com/problems/matrix-median/

int count(vector<int> &v, int num)
{
    int s=0, e=v.size()-1;
    
    while(s<=e)
    {
        int mid=(s+e)/2;
        
        if(v[mid]<=num) s=mid+1;
        
        else e=mid-1;
    }
    
    return s;
}

int Solution::findMedian(vector<vector<int> > &v) {
    
    int n=v.size(), m=v[0].size();
    
    int s=1, e=1e9;
    
    while(s<=e)
    {
        int mid=(s+e)/2;
        int cnt=0;
        
        for(int i=0;i<n;i++) cnt+=count(v[i],mid);
        
        if(cnt<=(n*m)/2) s=mid+1;
        
        else e=mid-1;
        
    }
    
    return s;
}
