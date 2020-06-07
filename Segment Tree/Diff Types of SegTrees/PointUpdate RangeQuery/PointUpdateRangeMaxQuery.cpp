// https://cses.fi/problemset/result/504426/
const int maxn = 2e5+10;
vector<int>t(maxn<<2);
int n,m;
void update(int rt,int l,int r,int pos,int new_val){
	if(l==r){t[rt]=new_val;return;}
	if(pos<=((l+r)>>1))update(rt<<1,l,(l+r)>>1,pos,new_val);
	else update((rt<<1)+1,((l+r)>>1)+1,r,pos,new_val);
	t[rt]=max(t[rt<<1],t[(rt<<1)+1]);
}
int query(int rt,int tl,int tr,int l,int r){
	if(l>r)return -1e15;
	if(l==tl&&r==tr)return t[rt];
	return max(query(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1)),query((rt<<1)+1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r));
}
