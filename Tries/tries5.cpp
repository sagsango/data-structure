#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tree{
	int count=0;
	tree*left=NULL;
	tree*right=NULL;
};

void insert(tree*root,int n)
{
	tree*current=root;
	current->count++;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1LL;
		if(b)
		{
			if(!current->right)current->right=new tree;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tree;
			current=current->left;
		}
		current->count++;
	}
}

int counter(tree*root,int n,int k)
{
	int count=0;
	tree*current=root;
	for(int i=31;i>=0 && current;i--)
	{
		int bit_n=(n>>i)&1LL;
		int bit_k=(k>>i)&1LL;
		if(bit_k==0)
		{
			if(bit_n==0)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}
		}
		else
		{
			if(bit_n==0)
			{
				if(current->left)count+=(current->left)->count;
				current=current->right;
			}
			else
			{
				if(current->right)count+=(current->right)->count;
				current=current->left;
			}
		}
	}
	return count;
}
	

int32_t main()
{
	int q;cin>>q;
	while(q--)
	{
		int n,k,ans=0;cin>>n>>k;
		tree*root=new tree;
		vector<int>a(n+1);
		insert(root,a[0]);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]^=a[i-1];
			insert(root,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			ans+=counter(root,a[i],k);
		}
		cout<<ans<<endl;
	}
}
