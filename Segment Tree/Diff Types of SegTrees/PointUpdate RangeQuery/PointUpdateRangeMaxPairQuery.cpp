// https://codeforces.com/gym/282397/submission/82188293

const int maxn = 1e5+10;
vector<pair<int,int>>t(4*maxn),a(maxn);
int n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = max( t[v*2] , t[v*2+1] );
    }
}

pair<int,int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {-1e18,-1};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, pair<int,int> new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max( t[v*2] , t[v*2+1] );
    }
}
