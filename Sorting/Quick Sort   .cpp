Merge Sort : NlogN  :recursion is used   :first function divide then sort and combine
Quick Sort : NlogN  :recursion is used   :first function sort 1 key element and then divide it into smaller tasks


#########################################################################################################################
#include<bits/stdc++.h>
using namespace std;
void quick_sort(vector<int>&v,int l,int r)
{
    if(l<=r)
    {
	    int key=v[l];
	    //now all the element less than or equal to key ,will be left size and rest right side
	    vector<int>small_elements,big_elements;
	    int Nsmaller=0,Nbigger=0;
	    //rest of the elements except the key
	    for(int i=l+1;i<=r;i++)
	    {
		    if(v[i]<=key)
		    {
			    small_elements.push_back(v[i]);
		            Nsmaller++;
		    }
		    else
		    {
			    big_elements.push_back(v[i]);
		            Nbigger++;
		    }
	    }
	   //now have fill back
	   int i,stop=0,btop=0;
	
	   for(i=l;i<l+Nsmaller;i++)
	   v[i]=small_elements[stop++];
	
	   v[i]=key;
	
	   for(i=i+1;i<l+Nsmaller+Nbigger;i++)
	   v[i]=big_elements[btop++];
	
	   //now have to make call for smaller partes
	   int mid=l+Nsmaller;
	   quick_sort(v,l,mid-1);
           quick_sort(v,mid+1,r);
    }
}	
int main()
{
	int size;
	cin>>size;
	vector<int>v(size);
	for(int i=0;i<size;i++)
	cin>>v[i];
	
	quick_sort(v,0,size-1);
	for(int i=0;i<size;i++)
	cout<<v[i]<<" ";
	cout<<endl;
}


########################################################################################################################
//Same 
#include<bits/stdc++.h>
using namespace std;
void quickSort(int input[], int size) {
  if(size<=1) return;
  int key=input[0];
  int *small_input=new int[size];
  int *big_input=new int[size];
  int stop=0,btop=0,top=0,ns=0,nb=0;
  //All element less than or equal to key will be on left side
  for(int i=1;i<size;i++)
  {
       if(input[i]<=key)
       {
             ns++;
             small_input[stop++]=input[i];
       }
       else
       {
             nb++;
             big_input[btop++]=input[i];
       }
  }
  stop=0,btop=0,top=0;
  while(stop<ns)
  {
       input[top++]=small_input[stop++];
  }
  input[top++]=key;
  while(btop<nb)
  {
       input[top++]=big_input[btop++];
  }
  
  quickSort(input,ns);
  quickSort(input+ns+1,nb);
}
int main()
{
	int input[1000];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	cin>>input[i];
	quickSort(input,size);
	for(int i=0;i<size;i++)
	cout<<input[i]<<" ";
}
