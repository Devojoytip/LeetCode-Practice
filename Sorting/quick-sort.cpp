// https://practice.geeksforgeeks.org/problems/quick-sort/1

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
       
       swap(a[low], a[j]); // j now has index of smallest no
       
       return j; // return index of smallest no
    }
};
