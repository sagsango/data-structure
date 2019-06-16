/*
 * 
 *Heap Testing
 *
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;

int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}
void shift_down(int i,int arr[],int size)
{
	int max_i=i,l=left(i),r=right(i);
	if(l<=size && arr[l]>arr[max_i])max_i=l;
	if(r<=size && arr[r]>arr[max_i])max_i=r;
	if(max_i==i)return;
	swap(arr[max_i],arr[i]);
	shift_down(max_i,arr,size);
}
void heap_sort(int arr[],int size)
{
	int sz=size;
	for(int i=size;i>=1;i--)shift_down(i,arr,size);
	for(int i=size;i>=1;i--)
	{
		swap(arr[sz],arr[1]);sz--;shift_down(1,arr,sz);
	}
}

int32_t main()
{
	int arr[1000000],n;cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	heap_sort(arr,n);
	for(int i=1;i<=n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
