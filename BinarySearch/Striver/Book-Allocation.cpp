// https://www.codingninjas.com/studio/problems/allocate-books_1090540?leftPanelTab=1

int findStudents(vector<int>& v, int n, int maxi) 
{
    int cnt=1;
    long long int pages=0;
    
    for(int i=0;i<n;i++)
    {
        if(pages+v[i]>maxi)
        {
            cnt++;
            pages=v[i];
        }

        else pages+=v[i];
    }

    return cnt;
}

int findPages(vector<int>& v, int n, int m) 
{
    //code here
    if(m>n) return -1;

    int s=0, e=0;
    
    for(int i=0;i<n;i++) 
    {
        e+=v[i];
        s=max(s,v[i]);
    }
    
    while(s<=e)
    {
        int mid=(s+e)/2;
        
        int cnt=findStudents(v,n,mid);
        
        if(cnt>m) s=mid+1;
        
        else e=mid-1;
    }
    
    return s;
}
