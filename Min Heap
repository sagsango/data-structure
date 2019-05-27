#include<bits/stdc++.h>
#define int long long
using namespace std;
class minheap{
	private:
	int h[1000000],sz=0;
	public:
	int parent(int i){return i/2;}
	int left(int i){return i*2;}
	int right(int i){return i*2+1;}
	void shift_up(int i)
	{
		if(i==1)return;
		int p=parent(i);
		if(h[p] > h[i])swap(h[p],h[i]);
		shift_up(p);
	}
	void shift_down(int i)
	{
		int min_i=i,l=left(i),r=right(i);
		if(l<=sz && h[l]<h[min_i])min_i=l;
		if(r<=sz && h[r]<h[min_i])min_i=r;
		if(min_i==i)return;
		swap(h[min_i],h[i]);
		shift_down(min_i);
	}
	void insert(int a){h[++sz]=a;shift_up(sz);}
	int extract_min()
	{
		int min=h[1];
		h[1]=h[sz--];
		shift_down(1);
		return min;
	}
	bool empty(){return sz==0;}
	int min(){return h[1];}
	int size(){return sz;}
	void remove(int i)
	{
		h[i]=LLONG_MIN;
		shift_up(i);
		extract_min();
	}
	void change_priority(int i,int p)
	{
		if(h[i]>p){h[i]=p;shift_up(i);}
		else {h[i]=p;shift_down(i);}
	}
};
int32_t main()
{
	minheap h;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;h.insert(x);  // Inserting elements in MinHeap
	}
	for(int i=1;i<=n;i++)
	{
		cout<<h.extract_min()<<" ";// Printing them non decreasing order.
	}
	cout<<endl;
}
