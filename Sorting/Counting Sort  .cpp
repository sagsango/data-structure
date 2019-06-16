void counting_sort(int arr,int n)
{
    // lest all elements arr[i]  [0,mx]
    int count[mx+1];
    for(int i=0;i<n;i++)count[ arr[i] ]++;
    int top=0;
    for(int i=0;i<=mx;i++)
    {
        while( count[i]-- )arr[top++]=i;
    }
}
