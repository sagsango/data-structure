void insertion_sort(int arr[],int n)
{ 
    for(int i=0;i<n;i++)
    {
        int crnt=arr[i];
        int j=i;
        while( j-1>=0 && arr[j-1] > crnt )
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=crnt;
            
    }
}
