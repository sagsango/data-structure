// https://cses.fi/problemset/result/504329/
const int maxn = 2e5+10;
vector<int>t(4*maxn),a(maxn);
int n,m;
void built(int rt,int l,int r){
	if( l == r ){t[rt]=a[l];return;}
	int m=(l+r)>>1;
	built(rt<<1,l,m);
	built((rt<<1)+1,m+1,r);
	t[rt]=min(t[(rt<<1)],t[(rt<<1)+1]);
}
void update(int rt,int l,int r,int pos,int new_val){
	if(l==r){t[rt]=new_val;return;}
	int m=(l+r)>>1;
	if(pos<=m)update(rt<<1,l,m,pos,new_val);
	else update((rt<<1)+1,m+1,r,pos,new_val);
	t[rt]=min(t[(rt<<1)],t[(rt<<1)+1]);
}
int query(int rt,int tl,int tr,int l,int r){
	if( l > r )return 1e15;
	if( l == tl && r == tr )return t[rt];
	int m=(tl+tr)>>1;
	return min(query(rt<<1,tl,m,l,min(r,m)),query((rt<<1)+1,m+1,tr,max(m+1,l),r));
}
