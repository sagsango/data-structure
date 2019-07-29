//minimum xor pair

#include<bits/stdc++.h>
#define int long long
using namespace std;

class tries{
	public:
	tries *left;
	tries *right;
};

void insert(tries*root,int n)
{
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(!current->right)current->right=new tries;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tries;
			current=current->left;
		}
	}
}

int min_xor(tries*root,int n)
{
	int _xor=0;
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			
			if(current->right)
			{
				current=current->right;
			}
			else 
			{
				current=current->left;
				_xor+=1<<i;
			}
		}
		else
		{
			if(current->left)
			{
				current=current->left;
			}
			else 
			{
				current=current->right;
				_xor+=1<<i;
			}
		}
	}
	return _xor;
}
int32_t main()
{
	tries *root = new tries;
	int n,ans=LLONG_MAX;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		ans=min(ans,min_xor(root,a[i]));
		insert(root,a[i]);
	}
	cout<<ans<<endl;
} 
