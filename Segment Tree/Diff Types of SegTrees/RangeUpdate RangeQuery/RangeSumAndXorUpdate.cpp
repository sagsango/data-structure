// https://codeforces.com/problemset/problem/242/E

class segtree{
	public:
	vector<int>t,lazy,a;
	segtree(){
		a = vector<int>(1e5+5);
		t = lazy = vector<int>(4e5+5);
	}
	void build(int v, int tl, int tr) {
	    if (tl == tr) {
	        t[v] = a[tl];
	    } else {
	        int tm = (tl + tr) / 2;
	        build( v*2, tl, tm);
	        build( v*2+1, tm+1, tr);
	        t[v] =  t[2*v] + t[2*v+1];
	    }
	}
	void push(int v,int l1,int r1,int l2,int r2){
		if( lazy[v] == 0 )return;
	    t[v*2] = (r1-l1+1) - t[2*v];
	    lazy[v*2] ^= lazy[v];
	    t[v*2+1] = (r2-l2+1) - t[2*v+1];
	    lazy[v*2+1] ^= lazy[v];
	    lazy[v] = 0;
	}
	void update(int v, int tl, int tr, int l, int r) {
	    if (l > r)
	        return;
	    if (l == tl && tr == r) {
	        t[v] = (r - l +1) - t[v];
	        lazy[v] ^=1;
	    } else {
	        int tm = (tl + tr) / 2;
	        push(v,tl,tm,tm+1,tr);
	        update(v*2, tl, tm, l, min(r, tm));
	        update(v*2+1, tm+1, tr, max(l, tm+1), r);
	        t[v] = t[v*2] + t[v*2+1];
	    }
	}
	int query(int v, int tl, int tr, int l, int r) {
	    if (l > r)
	        return 0;
	    if (l == tl && tr == r)
	        return t[v];
	    int tm = (tl + tr) / 2;
	    push(v,tl,tm,tm+1,tr);
	    return query(v*2, tl, tm, l, min(r, tm)) +
	               query(v*2+1, tm+1, tr, max(l, tm+1), r);
	}
};
int32_t main()
{
	IOS
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	segtree sg[21];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=20;j++){
			sg[j].a[i]=(a[i]>>j)&1;
		}
	}
	for(int i=0;i<=20;i++){
		sg[i].build(1,1,n);
	}
	int q;cin>>q;
	while( q-- ){
		int t;cin>>t;
		if( t == 1 ){
			int ans = 0 , l , r;cin>>l>>r;
			for(int i=0;i<=20;i++){
				ans+=sg[i].query(1,1,n,l,r) * (1LL<<i);
			}
			cout << ans  << endl;
		}
		else{
			int l,r,x;cin>>l>>r>>x;
			for(int i=0;i<=20;i++){
				if( (x>>i)&1 ){
					sg[i].update(1,1,n,l,r);
				}
			}
		}
	}
}
