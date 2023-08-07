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
    void quickSort(int arr[], int low, int high)
    {
        // code here
        qs(arr, low, high);
    }
    
    public:
    
    void qs(int arr[], int low, int high) {
        
        if (low>=high) return;
        
        int partitionIdx = partition(arr, low, high);
        
        qs(arr, low, partitionIdx - 1);
        
        qs(arr, partitionIdx + 1, high);
    }

    int partition (int a[], int low, int high)
    {
       // Your code here
       int i=low, j=high, pivot=a[low];
       
       while(i<j)
       {
           while(i<high and a[i]<=pivot) i++;
           
           while(j>low and a[j]>pivot) j--;
           
           if(i<j) swap(a[i], a[j]);
       }
       
       swap(a[low], a[j]);
       
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