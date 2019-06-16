#include<bits/stdc++.h>
using namespace std;


######################################################################################################################
void merge(int arr[],int l1,int r1,int l2,int r2)
{
	int tarr[abs(l1-r1)+1+abs(l2-r2)+1];
	int top1=l1,top2=l2,top=0;
	while(top1<=r1 && top2<=r2)
	{
		if(arr[top1]<arr[top2])
		tarr[top++]=arr[top1++];
		else
		tarr[top++]=arr[top2++];
	}
	while(top1<=r1)
	tarr[top++]=arr[top1++];
	while(top2<=r2)
	tarr[top++]=arr[top2++];

	top1=0;top2=l1;
	while(top2<=r2)
	{
		arr[top2]=tarr[top1++];
		if(top2==r1)
		top2=l2;
		else
		top2++;
	}
}

void m_sort(int arr[],int l,int r)
{
	if(l==r)
	return;
	else
	{
	    int m=(l+r)/2;
	    m_sort(arr,l,m);
	    m_sort(arr,m+1,r);
	    merge(arr,l,m,m+1,r);
	}
}
int main()
{
	int size;cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	cin>>arr[i];
	m_sort(arr,0,size-1);
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}


###################################################################################################################

//Same but better implimentation
#include<bits/stdc++.h>
using namespace std;
void mergeSort(int input[], int size){
  if(size>1)
  {
      int mid=(size)/2;
      mergeSort(input,size/2);
      mergeSort(input+mid,(size+1)/2);
     
      int*temp=new int[size];
      int top1=0,top2=mid,top=0;
      while(top1<mid && top2<size)
      {
          if(input[top1]<input[top2])
            temp[top++]=input[top1++];
          else
            temp[top++]=input[top2++];
      }
      while(top1<mid)
      {
          temp[top++]=input[top1++];
      }
      while(top2<size)
      {
          temp[top++]=input[top2++];
      }
      top1=0,top2=0;
      while(top1<size)
      {
          input[top1++]=temp[top2++];
      }
     
  }
}
int main()
{
	int input[1000];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	cin>>input[i];
	mergeSort(input,size);
	for(int i=0;i<size;i++)
	cout<<input[i]<<" ";
}
