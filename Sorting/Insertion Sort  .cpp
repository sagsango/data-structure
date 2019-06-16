void insertion_sort(int arr[],int n)
{ 
    for(int i=0;i<n;i++)
    {
        int j=i;
        while( j-1 >= 0  && arr[j-1] > arr[i] )j--;
        swap(arr[j],arr[i]);
    }
}
