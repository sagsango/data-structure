//Testing   :     https://www.hackerearth.com/challenges/competitive/january-circuits-20/algorithm/equal-subarrays-cf01a26a/


/* No updation and range query : min[l,r] max[l,r] sum[l,r]*/
struct node{
	int mn,mx,sm;
};

const int N=1e5+10;
vector<node>t(4*N+1);
vector<int>a(N+1);

void built(int v,int tl,int tr)
{
    if(tl==tr)
    {
      t[v].mn=a[tl];
      t[v].mx=a[tl];
      t[v].sm=a[tl];
      
    }
    else
    {
       int tm=(tl+tr)/2;
       built(2*v,tl,tm);
       built(2*v+1,tm+1,tr);
       t[v].mn=min(t[2*v].mn,t[2*v+1].mn);
       t[v].sm=t[2*v].sm+t[2*v+1].sm;
       t[v].mx=max(t[2*v].mx,t[2*v+1].mx);
    }
}
node query(int v,int tl,int tr,int l,int r)
{
      if(tl > tr || l  > r )
      {
		  return {1000000000,-1000000000,0};     /* Take care of inf */
	  }
      if(tl==l && tr==r )
      {
          return t[v];
      }
      else
      {
          int tm=(tl+tr)/2;
          node a = query(2*v ,tl ,tm , l ,min(r,tm) );
          node b = query(2*v+1 , tm+1 , tr , max(l,tm+1) , r );
          return { min(a.mn,b.mn) , max(a.mx,b.mx) , a.sm+b.sm };
      }
    /***
    * Program is  tested 
    ***/
}
