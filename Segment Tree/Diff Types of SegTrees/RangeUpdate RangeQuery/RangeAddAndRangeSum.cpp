// Tested :   https://codeforces.com/gym/262913/submission/68430180
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] =  t[2*v] + t[2*v+1];
    }
}

void push(int v,int l1,int r1,int l2,int r2){
    t[v*2] += lazy[v]*(r1-l1+1);
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v]*(r2-l2+1);
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend * (r - l +1);  
        lazy[v] += addend;
    } else {
        int tm = (tl + tr) / 2;
        push(v,tl,tm,tm+1,tr);
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    push(v,tl,tm,tm+1,tr);
    return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}


