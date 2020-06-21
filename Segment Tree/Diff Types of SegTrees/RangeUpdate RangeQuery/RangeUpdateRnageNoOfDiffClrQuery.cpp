//  https://codeforces.com/gym/284118/submission/84037140
//  No of diff clr = 0 to 63
const int maxn = 4e5+10;
vector<int>g[maxn],a(maxn),pos(maxn),subtree(maxn),t(maxn<<2),lazy(maxn<<2);
int n,m,cur_pos=0;
void push(int rt){
	if(!lazy[rt])return;
	t[rt<<1]=t[rt<<1|1]=lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=0;
}
void update(int rt,int tl,int tr,int l,int r,int new_val){
	if( l > r )return;
	if( tl == l && tr == r ){ t[rt] = lazy[rt] = new_val ; return; }
	push(rt);
	update(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),new_val);
	update(rt<<1|1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r,new_val);
	t[rt]=t[rt<<1]|t[rt<<1|1];
}
int query(int rt,int tl,int tr,int l,int r){
	if( l > r )return 0;
	if( tl == l && tr == r )return t[rt];
	push(rt);
	int ans = query(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1))|query(rt<<1|1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r);
	t[rt]=t[rt<<1]|t[rt<<1|1];
	return ans;
}
