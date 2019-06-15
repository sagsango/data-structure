#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<float,int> fi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<fi> vfi;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef priority_queue<fi> pqfi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii; 
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi; 


template <typename T>
class BIT{
	// binary index tree or fenwik tree
	// index starts from 1 to n
	int *fen, size;
public:
    // allocate memory
	BIT(int n) {
		size = n;
		fen = new T [n+1];
	}
	// free memory
	~BIT() {
		delete [] fen;
	}
    // sum of the prifix till pth position
	T sum(int p) {
		T ans = 0;
	    for(int i = p;i;i -= i & -i)
		ans += fen[i];
	    return ans;
	}
	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int p,T val){
	    for(int i = p;i <= size;i += i & -i)
		fen[i] += val;
    }
    // divide each original frequency by c
	void scaleDown(T c){
        for (int i=1 ; i<=size ; i++) fen[i] /= c;
    }
    // multiply each original frequency by c
    void scaleUp(T c){
        for (int i=1 ; i<=size ; i++) fen[i] *= c;
    }
};


int32_t main()
{
	IOS
	BIT<int>bit(10);
	
	for(int i=1;i<=10;i++)
	{    
		//Taking the array elements
		int x;cin>>x;bit.update(i,x);
	}
	
	// Now perform required updation and sum query
	
	
	
}

			
