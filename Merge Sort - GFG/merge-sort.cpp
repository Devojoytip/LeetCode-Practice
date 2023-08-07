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