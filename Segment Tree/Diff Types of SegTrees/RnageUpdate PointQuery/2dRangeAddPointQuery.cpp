const int N=1e6;
int lazy[2][4*N];

void push(int v) {
      lazy[0][2*v]=lazy[0][v];
      lazy[1][2*v]=lazy[1][v];
      
      lazy[0][2*v+1]=lazy[0][v];
      lazy[1][2*v+1]=lazy[1][v];
      
      lazy[0][v]=0;
      lazy[1][v]=0;
}

void update(int v, int tl, int tr, int l, int r, int new_val,int parity) {
    if (l > r || tl > tr) 
        return;
    if (l == tl && tr == r) {
        lazy[parity][v]+=new_val;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

pair<int,int> get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return {lazy[0][v],lazy[1][v]};
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}
