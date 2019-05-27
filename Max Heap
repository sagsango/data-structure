#include<bits/stdc++.h>
#define int long long
using namespace std;
class maxheap{
	private:
	int h[1000000],sz=0;
	public:
	int parent(int i){return i/2;}
	int left(int i){return 2*i;}
	int right(int i){return 2*i+1;}
	void shift_up(int i)
	{
		if(i==1)return ;
		int p=parent(i);
		if(h[i] > h[p])swap(h[i],h[p]);
		shift_up(p);
	}
	void shift_down(int i)
	{
		int max_i=i,l=left(i),r=right(i);
		if(l<=sz && h[l] >h[max_i])max_i=l;
		if(r<=sz && h[r] >h[max_i])max_i=r;
		if(i==max_i)return;
		swap(h[i],h[max_i]);
		shift_down(max_i);
	}
	void insert(int a){h[++sz]=a;shift_up(sz);}
	int extract_max()
	{
		int max=h[1];
		h[1]=h[sz--];
		shift_down(1);
		return max;
	}
	bool empty(){return sz==0;}
	int max(){return h[1];}
	int size(){return sz;}
	void remove(int i)
	{
		h[i]=LLONG_MAX;
		shift_up(i);
		extract_max();
	}
	void change_priority(int i,int p)
	{
		if(h[i] > p){h[i]=p;shift_down(i);}
		else{h[i]=p;shift_up(i);}
	}
};
int32_t main()
{
	maxheap h;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;h.insert(x);  // Inserting N elements
	}
	for(int i=1;i<=n;i++)
	{
		cout<<h.extract_max()<<endl;// Displaying N elements in non increasing order
	}
}



