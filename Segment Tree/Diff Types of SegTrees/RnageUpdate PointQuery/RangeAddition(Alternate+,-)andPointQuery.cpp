// https://codeforces.com/gym/284118/submission/83763574
int lazy[maxn<<3][2];
int n,m,timer=0;
void push(int r){
	lazy[r<<1][0]+=lazy[r][0];
	lazy[r<<1][1]+=lazy[r][1];
	lazy[r<<1|1][0]+=lazy[r][0];
	lazy[r<<1|1][1]+=lazy[r][1];
	lazy[r][0]=lazy[r][1]=0;
}
void update(int rt,int tl,int tr,int l,int r,int val,int p){
	if( l > r )return;
	if( tl == l && tr == r){lazy[rt][p]+=val;return;}
	push(rt);
	update(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),val,p);
	update(rt<<1|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,val,p);
}
int  query(int rt,int tl,int tr,int pos,int p){
	if( tl == tr ) return lazy[rt][p]-lazy[rt][p^1];
	push(rt);
	if(pos<=(tl+tr)>>1)return query(rt<<1,tl,(tl+tr)>>1,pos,p);
	return query(rt<<1|1,((tl+tr)>>1)+1,tr,pos,p);
}
