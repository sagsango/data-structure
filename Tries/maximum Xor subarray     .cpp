//maximum xor subarray 

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
	
	for(int i=1;i<n;i++)a[i]^=a[i-1];
	
	for(int i=0;i<n;i++)insert(root,a[i]);
	for(int i=0;i<n;i++)ans=max(ans,max_xor(root,a[i]));
	cout<<ans<<endl;
} 
/*############################################################################*/
https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
#include<bits/stdc++.h> 
using namespace std; 
#define INT_SIZE 32 
struct TrieNode 
{ 
    int value;
    TrieNode *arr[2]; 
}; 
TrieNode *newNode() 
{ 
    TrieNode *temp = new TrieNode; 
    temp->value = 0; 
    temp->arr[0] = temp->arr[1] = NULL; 
    return temp; 
}  
void insert(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        bool val = pre_xor & (1<<i); 
        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 
        temp = temp->arr[val]; 
    } 
    temp->value = pre_xor; 
} 
int query(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        bool val = pre_xor & (1<<i);
        if (temp->arr[1-val]!=NULL) 
            temp = temp->arr[1-val]; 
        else if (temp->arr[val] != NULL) 
            temp = temp->arr[val]; 
    } 
    return pre_xor^(temp->value); 
} 
  

int maxSubarrayXOR(int arr[], int n) 
{ 
    TrieNode *root = newNode(); 
    insert(root, 0);
    
    /*
     * 
     * Zero has been inserted
     * 
     */ 

    int result = INT_MIN, pre_xor =0; 
    for (int i=0; i<n; i++) 
    { 
        pre_xor = pre_xor^arr[i]; 
        insert(root, pre_xor); 
        result = max(result, query(root, pre_xor)); 
    } 
    return result; 
} 
int main() 
{ 
    int arr[] = {8, 1, 2, 12}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n); 
    return 0; 
}
/*########################################################################################*/
