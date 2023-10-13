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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int a[], int s, int e)
    {
        // code here
        if(s>=e) return;
        int idx=partition(a,s,e);
        quickSort(a,s,idx-1);
        quickSort(a,idx+1,e);
    }
    
    public:
    int partition (int a[], int s, int e)
    {
       // Your code here
       int i=s,j=e,pvt=a[s];
       
       while(i<j)
       {
           while(i<e and a[i]<=pvt) i++;
           
           while(j>s and a[j]>pvt) j--;
           
           if(i<j) swap(a[i],a[j]);
       }
       
       swap(a[s],a[j]);
       
       return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends