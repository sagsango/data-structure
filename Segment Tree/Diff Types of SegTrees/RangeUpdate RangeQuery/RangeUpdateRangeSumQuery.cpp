// https://codeforces.com/gym/284118/submission/83903790
const int maxn = 5e5+10;
vector<int>t(maxn<<3),lazy(maxn<<3,-1);
int n;
void push(int rt,int tl,int tr){
	if( lazy[rt] == -1 )return;
	int m = (tl+tr)>>1;
	t[rt<<1]=lazy[rt]*(m-tl+1);
	t[rt<<1|1]=lazy[rt]*(tr-m);
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=-1;
}
void update(int rt,int tl,int tr,int l,int r,int new_val){
	if( l > r )return ;
	if( tl == l && tr == r ){t[rt]=new_val*(tr-tl+1);lazy[rt]=new_val;return;}
	push(rt,tl,tr);
	update(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),new_val);
	update(rt<<1|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,new_val);
	t[rt]=t[rt<<1]+t[rt<<1|1];
}
int sum(int rt,int tl,int tr,int l,int r){
	if( l > r )return 0;
	if( tl == l && tr == r )return t[rt];
	push(rt,tl,tr);
	int ans = sum(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1))+sum(rt<<1|1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r);
	t[rt]=t[rt<<1]+t[rt<<1|1];
	return ans;
}
