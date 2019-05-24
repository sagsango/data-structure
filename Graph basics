#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
void fastio()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    
    	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
ll llin(){ll x;scanf("%lld",&x);return x;}
ld ldin(){ld x;scanf("%Lf",&x);return x;}
char chin(){char ch;cin>>ch;return ch;}
string strin(){string str;cin>>str;return str;}


void explore(ll i,vector<vector<ll>>&V,vector<bool>&visited,vector<ll>&previsit,vector<ll>&postvisit)
{
	static ll count=0;
	visited[i]=true;
	cout<<i<<endl;
	previsit[i]=++count;
	for(ll j=0;j<(ll)V[i].size();j++)
	{
		if(!visited[V[i][j]])
			explore(V[i][j],V,visited,previsit,postvisit);
	}
	postvisit[i]=++count;
}

ll dfs(vector<vector<ll>>&V,vector<bool>&visited,vector<ll>&previsit,vector<ll>&postvisit,ll v)
{
	int components=0;
	for(ll i=1;i<=v;i++)
	{
		if(!visited[i])
		{
			components++;
			explore(i,V,visited,previsit,postvisit);
		}
	}
	return components;

}
int main()
{
	fastio();
	////--START FROM HERE--////

	/*
	It is for undirected graph 
	can have cycle
	can hev no cycle
	*/

	//"Enter no of verticies  and edges:";
	ll v=llin(),e=llin();
	vector<vector<ll>>V(v+1);
	vector<ll>previsit(v+1);
	vector<ll>postvisit(v+1);
	vector<bool>visited(v+1,false);
	for(ll i=0;i<e;i++)
	{
		ll x=llin();
		ll y=llin();
		V[x].push_back(y);
		V[y].push_back(x);

	}
	for(ll i=1;i<=v;i++)
	{
		cout<<i<<":";
		for(ll j=0;j<(ll)V[i].size();j++)
			cout<<V[i][j]<<" ";
		cout<<endl;
	}
	int components=dfs(V,visited,previsit,postvisit,v);
	cout<<"components:"<<components<<endl;
	for(int i=1;i<=v;i++)
		cout<<i<<" "<<previsit[i]<<" "<<postvisit[i]<<endl;

	/*
	If two verticies u and v belongs to same components then
	previsit( u ) < previsit( v ) < postvisit( v ) < postvisit( u )
	or
	previsit( v ) < previsit( u ) < postvisit( u ) < postvisit( v )
	*/

	/*
	If it were undirected acyclic graph
	then we can easly found the leaf
	the vertex wicth all its neighbours already has been traversed
	*/

	/*
	If it were DAG
	then we can easly found the leaf
	the vertex wihich all its neighbours are zero
	*/

	/*TOPOLOGICAL SORTING
	sort the vertices decreasing order of postvisit number
	*/

	return 0;
}
