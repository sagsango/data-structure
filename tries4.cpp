//minimum xor pair

#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
{
	int n,ans=LLONG_MAX;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	
	for(int i=0;i<n-1;i++)ans=min(ans,a[i]^a[i+1]);
	cout<<ans<<endl;
}
