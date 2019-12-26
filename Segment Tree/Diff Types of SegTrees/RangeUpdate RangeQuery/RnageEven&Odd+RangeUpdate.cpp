Problem    : https://codeforces.com/gym/262913/problem/C
source     : https://codeforces.com/gym/262913/submission/67651275

           : when built tree it will contain initial even odd sum in each range
           : when updated by odd number then even odd count get swaped for each corrsponding interval
           : here each updaetion was odd
      
      
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=400000+1;
vector<vector<int>>t(2,vector<int>(4*N+1));
vector<int>lazy(4*N+1);
vector<int>a(N+1);
vector<int>val(N+1);
vector<int>in(N+1);
vector<int>out(N+1);
vector<int> g[N+1];
int n,vt=0;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[a[tl]%2][v]++;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[0][v] = t[0][2*v] + t[0][2*v+1];
        t[1][v] = t[1][2*v] + t[1][2*v+1];
    }
}

void push(int v) {
	if(!lazy[v])return;
    lazy[v*2] ^= lazy[v];
    lazy[v*2+1] ^= lazy[v];
    lazy[v] = 0;
    swap(t[0][2*v+1],t[1][2*v+1]);
    swap(t[0][2*v],t[1][2*v]);
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r || tl > tr) 
        return;
    if (l == tl && tr == r) {
		swap(t[0][v],t[1][v]);
        lazy[v] ^= 1;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
        t[0][v] = t[0][2*v] + t[0][2*v+1];
        t[1][v] = t[1][2*v] + t[1][2*v+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r || tl > tr)
        return 0;
    if (l == tl && tr == r)
        return t[1][v];
    push(v);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void dfs(int u,int p)
{
	in[u]=++vt;
	for(auto v:g[u])
	if(v!=p)dfs(v,u);
	out[u]=++vt;
	
	a[in[u]]=val[u];
	a[out[u]]=val[u];
}
int32_t main()
{
	IOS
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int p;cin>>p;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	for(int i=1;i<=n;i++)
	cin>>val[i];
	
	dfs(1,0);
	build(1,1,2*n);
	int q;cin>>q;
	while(q--)
	{
		string s;cin>>s;
		int u;cin>>u;
		
		if( s=="get" )cout<<query(1,1,2*n,in[u],out[u])/2<<endl;
		else update(1,1,2*n,in[u],out[u]);
		
		
		
	}
	
}
      
