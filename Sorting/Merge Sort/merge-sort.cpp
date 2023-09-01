// https://practice.geeksforgeeks.org/problems/merge-sort/1

class Solution
{
    public:
    void merge(int a[], int l, int mid, int r)
    {
         // Your code here
        int i=l, j=mid+1;
        vector<int> v; 
        
        while(i<=mid and j<=r)
        {
            if(a[i]>a[j]) 
            {
                v.push_back(a[j]);
                j++;
            }
            else
            {
                v.push_back(a[i]);
                i++;
            }
        }
        
        while(i<=mid)
        {
            v.push_back(a[i]);
            i++;
        }
        
        while(j<=r)
        {
            v.push_back(a[j]);
            j++;
        }
        
        for(int k=l;k<=r;k++)
        {
            a[k]=v[k-l];
        }
    }
    
    void mergeSort(int a[], int l, int r)
    {
        //code here
        
        if(l>=r) return;
        
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
};
