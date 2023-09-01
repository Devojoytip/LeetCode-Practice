// https://practice.geeksforgeeks.org/problems/bubble-sort/1

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int a[], int n)
    {
        // Your code here
        
        for(int i=0;i<n;i++)
        {
            bool swapped=0;
            
            for(int j=0;j<n-i;j++)
            {
                if(j>0 and a[j-1]>a[j]) 
                {
                    swap(a[j-1], a[j]);
                    swapped=1;
                }
            }
            
            if(!swapped) break;
        }
    }
};
