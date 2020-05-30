/* No updation and range query : min[l,r] max[l,r] */

const int maxn=3e5+5;
vector<int>t(4*maxn),a(maxn),lg(maxn);
 
 
#define __gcd newgcd
 
int __gcd(int a,int b){
	if( !a || !b ) return a + b;
	if( a > b    ) return __gcd(a%b,b);
	return __gcd(a,b%a);
}
 
void built(int v,int tl,int tr)
{
    if(tl==tr){
		t[v]=a[tl];
        return;
    }
    int tm=(tl+tr)/2;
    built(2*v,tl,tm);
    built(2*v+1,tm+1,tr);
    t[v]=__gcd(t[2*v],t[2*v+1]);
}
int query(int v,int tl,int tr,int l,int r)
{
    if(tl > tr || l  > r )return 0;
    if(tl==l && tr==r ) return t[v];
    int tm=(tl+tr)/2;
    return __gcd(  query(2*v,tl,tm,l,min(r,tm)) , query(2*v+1,tm+1,tr,max(l,tm+1),r) );
    /***
    * Program is  tested 
    ***/
}
