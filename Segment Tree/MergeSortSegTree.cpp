source code : https://codeforces.com/contest/811/submission/27382991
Tutorial    :https://codeforces.com/contest/811/submission/27382991

int n, m;
int a[MAX];
 
int mid(int i, int j)
{
    return (i + (j - i) / 2);
}
 
struct megh
{
    vector < int > v;
}seg[4*MAX];
 
void build(int node, int i, int j)
{
    if(i == j)
    {
        seg[node].v.push_back(a[i]);
    }
    else
    {
        build(2*node, i, mid(i, j));
        build(2*node + 1, mid(i, j) + 1, j);
        merge(seg[2*node].v.begin(), seg[2*node].v.end(), seg[2*node + 1].v.begin(), seg[2*node + 1].v.end(), back_inserter(seg[node].v));
    }
}
 
int query(int node, int i, int j, int l, int r, int val)
{
    if(i > j || i > r || l > j)
        return 0;
    else if(i >= l && j <= r)
    {
        return lower_bound(seg[node].v.begin(), seg[node].v.end(), val) - seg[node].v.begin();
    }
    else
        return (query(2*node, i, mid(i, j), l, r, val) + query(2*node + 1, mid(i, j) + 1, j, l, r, val));
}
 
