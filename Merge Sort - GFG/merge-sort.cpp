//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int a[], int l, int m, int r)
    {
         // Your code here
        int i=l, j=m+1, k=0;
        vector<int> t(r-l+1, 0);
        
        while(i<=m and j<=r)
        {
            if(a[i]<a[j])
            {
                t[k]=a[i];
                k++;
                i++;
            }
            else
            {
                t[k]=a[j];
                k++;
                j++;
            }
        }
        
        while(i<=m)
        {
            t[k]=a[i];
            k++;
            i++;
        }
        
        while(j<=r)
        {
            t[k]=a[j];
            k++;
            j++;
        }
        
        for(k=l;k<=r;k++) a[k]=t[k-l];
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

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends