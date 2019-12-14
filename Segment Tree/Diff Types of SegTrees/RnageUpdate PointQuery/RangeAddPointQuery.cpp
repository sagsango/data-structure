source : https://codeforces.com/gym/262908/submission/66887551

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
