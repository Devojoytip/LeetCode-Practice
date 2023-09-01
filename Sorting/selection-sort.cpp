// https://practice.geeksforgeeks.org/problems/selection-sort/1

class Solution
{
    public:
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        int n;
        cin>>n;
        int a[1005];
        
        for(int i=0;i<n;i++) cin>>a[i];
        
        selectionSort(a,n);
        
        return 1;
    }
     
    void selectionSort(int a[], int n)
    {
       //code here
       
       for(int i=0;i<n;i++)
       {
           int minIdx=i;
           
           for(int j=i+1;j<n;j++)
           {
               if(a[minIdx]>a[j]) minIdx=j;
           }
           
           swap(a[minIdx], a[i]);
       }
    }
};
