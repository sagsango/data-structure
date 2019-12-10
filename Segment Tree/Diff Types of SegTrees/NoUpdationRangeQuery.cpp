/* No updation and range query : min[l,r] max[l,r] */

const int N=1e5;
vector<int>t(4*N);

void built(vector<int>&a,int v,int tl,int tr)
{
    if(tl==tr)
    {
      t[v]=a[tl];
    }
    else
    {
       int tm=(tl+tr)/2;
       built(a,2*v,tl,tm);
       built(a,2*v+1,tm+1,tr);
       t[v]=min(t[2*v],t[2*v+1]);
    }
}
int query(int v,int tl,int tr,int l,int r)
{
      if(tl > tr || l  > r )return -1e18;
      if(tl==l && tr==r )
      {
          return t[v];
      }
      else
      {
          int tm=(tl+tr)/2;
          return min(  query(2*v ,tl ,tm , l ,min(r,tm) ) ,
                       query(2*v+1 , tm+1 , tr , max(l,tm+1) , r ));
      }
}
