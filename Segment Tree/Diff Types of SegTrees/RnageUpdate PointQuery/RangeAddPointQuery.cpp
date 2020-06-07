// https://cses.fi/problemset/result/504376/
const int maxn = 2e5+10;
vector<int>lazy(maxn<<2);
int n,m;
void push(int r){
	lazy[r<<1]+=lazy[r];
	lazy[(r<<1)+1]+=lazy[r];
	lazy[r]=0;
}
void update(int rt,int tl,int tr,int l,int r,int addend){
	if(l>r)return;
	if(l==tl&&r==tr){lazy[rt]+=addend;return;}
	push(rt);
	update((rt<<1),tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),addend);
	update((rt<<1)+1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,addend);
}
int query(int rt,int tl,int tr,int pos){
	if(tl==tr)return lazy[rt];
	push(rt);
	if(pos<=((tl+tr)>>1))return query(rt<<1,tl,(tl+tr)>>1,pos);
	return query((rt<<1)+1,((tl+tr)>>1)+1,tr,pos);
}





//   https://codeforces.com/gym/262908/submission/66887551
const int N=1e6;
int lazy[4*N];

void push(int v) {
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
      lazy[v]=0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r || tl > tr) 
        return;
    if (l == tl && tr == r) {
        lazy[v]+=addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return lazy[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}
