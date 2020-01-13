// https://codeforces.com/contest/1285/submission/68541677

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int solve(vector<int>v,int b){
	if( b < 0 )return 0;
	vector<int>v0,v1;
	int n=v.size();
	for(int i=0;i<n;i++){
		if( (v[i]>>b)&1 )v1.push_back(v[i]);
		else v0.push_back(v[i]);
	}
	if( v0.size()==0)return solve(v1,b-1);
	if( v1.size()==0)return solve(v0,b-1);
	int x0=solve(v0,b-1);
	int x1=solve(v1,b-1);
	return (1LL<<b | min( x0,x1));
}
	
	
int32_t main() {
   IOS
   int n;cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
	   cin>>v[i];
   }
   cout<< solve(v,30) << endl;
  
}
