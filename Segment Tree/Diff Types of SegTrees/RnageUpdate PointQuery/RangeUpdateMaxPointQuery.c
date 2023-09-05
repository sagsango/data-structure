
template<class type>
class segtree{
	private:  vector<type>lazy; int n;
	public:   segtree(int n){ lazy = vector<type>((n<<2)+10); this->n = n; }
	#define tm  ((tl+tr)>>1)
	void push(int rt){
		lazy[rt<<1|0]=max(lazy[rt],lazy[rt<<1|0]);
		lazy[rt<<1|1]=max(lazy[rt],lazy[rt<<1|1]); 
	}
	void update(int rt,int tl,int tr,int l,int r,type new_val){
		if( l > r ) return;
		if( tl == l && tr == r ){ lazy[rt]=max(lazy[rt],new_val); return; }
		push(rt); 
		update(rt<<1|0,tl,tm,l,min(r,tm),new_val);
		update(rt<<1|1,tm+1,tr,max(tm+1,l),r,new_val);
	}
	type query(int rt,int tl,int tr,int pos){
		if( tl == tr) return lazy[rt];
		push(rt);
		if( pos <= tm) return query(rt<<1|0,tl,tm,pos);
		return query(rt<<1|1,tm+1,tr,pos);
	}
};


// https://codeforces.com/gym/268390/problem/Z

const int maxn = 1e6 + 10;
vector<int>lazy(4*n+10);
segtree(int n){
	lazy = vector<int>(4*n+10,-1);
}
void push(int v) {
      lazy[2*v]=max(lazy[v],lazy[2*v]);
      lazy[2*v+1]=max(lazy[v],lazy[2*v+1]);
}
 
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r || tl > tr) 
        return;
    if (l == tl && tr == r) {
        lazy[v]=max(lazy[v],addend);
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
