// Maximum xor value pair

#include<bits/stdc++.h>
#define int long long
using namespace std;

class tries{
	public:
	tries *left;
	tries *right;
};


/*
struct node{
struct node * child[2]={NULL,NULL};
};



void insert(struct node*root,int n)
{
  struct node*head=root;
  for(int bit=62;bit>=0;bit--)
  {
       int b=(n>>bit)&1;
       if(head->child[b]==NULL)head->child[b]=new node;
       head=head->child[b];
  }
}



int max_xor(struct node*root,int n)
{
   int xor=0;
   struct node*head=root;
   for(int bit=62;bit>=0;bit--)
   {
       int b=(n>>bit)&1;
       if(head->child[b^1])
       {
           xor+=1LL<<bit;
           head=head->child[b^1];
       }
       else head=head->child[b];
   }
}
       
  
*/
   
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

int max_xor(tries*root,int n)
{
	int _xor=0;
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(current->left)
			{
				current=current->left;
				_xor+=1<<i;
			}
			else
			{
				current=current->right;
			}
		}
		else
		{
			if(current->right)
			{
				current=current->right;
				_xor+=1<<i;
			}
			else
			{
				current=current->left;
			}
		}
	}
	return _xor;
}
int32_t main()
{
	tries *root = new tries;
	int n,ans=0;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)insert(root,a[i]);
	for(int i=0;i<n;i++)ans=max(ans,max_xor(root,a[i]));
	cout<<ans<<endl;
} 
