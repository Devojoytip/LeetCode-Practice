// https://practice.geeksforgeeks.org/problems/insertion-sort/1


class Solution
{
    public:
    void select(int a[], int n)
    {
        // code here such that selectionSort() sorts arr[]
        insertionSort(a,n);
    }
    
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int a[], int n)
    {
        //code here
        
        for(int i=0;i<n;i++)
        {
            int j=i;
            
            while(j>0 and a[j-1]>a[j])
            {
                // swap(a[j-1], a[j]);
                
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                j--;
            }
        }
    }
};
