// https://cses.fi/problemset/result/504301/
const int maxn = 2e5+10;
vector<int>t(4*maxn),a(maxn);
int n,m;
void built(int rt,int l,int r){
	if(l==r){t[rt]=a[l];return;}
	int m=(l+r)>>1;
	built(rt<<1,l,m);
	built((rt<<1)+1,m+1,r);
	t[rt]=t[(rt<<1)]+t[(rt<<1)+1];
}
void update(int rt,int l,int r,int pos,int new_val){
	if(l==r){t[rt]=new_val;return;}
	int m=(l+r)>>1;
	if(pos<=m)update(rt<<1,l,m,pos,new_val);
	else update((rt<<1)+1,m+1,r,pos,new_val);
	t[rt]=t[(rt<<1)]+t[(rt<<1)+1];
}
int query(int rt,int tl,int tr,int l,int r){
	if(l>r)return 0;
	if(l==tl && r==tr)return t[rt];
	int m=(tl+tr)>>1;
	return query(rt<<1,tl,m,l,min(r,m))+query((rt<<1)+1,m+1,tr,max(m+1,l),r);
}



// tested
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r || tl > tr) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
