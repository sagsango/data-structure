see  : https://codeforces.com/gym/262908/submission/66818759

const int maxn = 1e6;
//vector<int>tmax(maxn<<2),tmin(maxn<<2),lazy(maxn<<2);
//vector<char>a(maxn);
char a[maxn];
int tmax[maxn<<2];
int tmin[maxn<<2];
int lazy[maxn<<2];
#define tm ((tl+tr)>>1)
void push(int rt){
	tmax[rt<<1]+=lazy[rt];
	tmin[rt<<1]+=lazy[rt];
	lazy[rt<<1]+=lazy[rt];
	tmax[rt<<1|1]+=lazy[rt];
	tmin[rt<<1|1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}
void update(int rt,int tl,int tr,int l,int r,int addend){
	if( l > r ) return;
	if( tl == l && tr == r ){ 
		tmax[rt]+=addend,tmin[rt]+=addend,lazy[rt]+=addend;
		return;
	}
	push(rt);
	update(rt<<1,tl,tm,l,min(r,tm),addend);
	update(rt<<1|1,tm+1,tr,max(l,tm+1),r,addend);
	tmax[rt]=max(tmax[rt<<1],tmax[rt<<1|1]);
	tmin[rt]=min(tmin[rt<<1],tmin[rt<<1|1]);
}
pair<int,int> query(int rt,int tl,int tr,int l,int r){// max,min
	if( l > r ) return {-1e9,+1e9};
	if( tl == l && tr == r ) return {tmax[rt],tmin[rt]};
	push(rt);
	pair<int,int> ql = query(rt<<1,tl,tm,l,min(r,tm));
	pair<int,int> qr = query(rt<<1|1,tm+1,tr,max(tm+1,l),r);
	return {max(ql.first,qr.first),min(ql.second,qr.second)};
}

--------------------------------------------------------------------------------------------------------------------------
    
const int MAXN=1e6+1;
const int inf = 1e9;
char a[MAXN];
int tmax[4*MAXN];
int tmin[4*MAXN];
int lazy[4*MAXN];
/* root will start from 1 , Not 0 */

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tmax[v] = a[tl];
        tmin[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tmax[v] = max( tmax[2*v] , tmax[2*v+1] );
        tmin[v] = min( tmin[2*v] , tmin[2*v+1] );
    }
}

void push(int v) {
    tmax[v*2] += lazy[v];
    tmin[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tmax[v*2+1] += lazy[v];
    tmin[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tmax[v] += addend;
        tmin[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        tmax[v] = max(tmax[v*2], tmax[v*2+1]);
        tmin[v] = min(tmin[v*2], tmin[v*2+1]);
    }
}

pair<int,int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {-inf,+inf};
    if (l <= tl && tr <= r)
        return {tmax[v],tmin[v]};
    push(v);
    int tm = (tl + tr) / 2;
    pair<int,int> ql = query(v*2, tl, tm, l, min(r, tm));
    pair<int,int> qr = query(v*2+1, tm+1, tr, max(l, tm+1),r);
    return {max(ql.first,qr.first),min(ql.second,qr.second)};
}
