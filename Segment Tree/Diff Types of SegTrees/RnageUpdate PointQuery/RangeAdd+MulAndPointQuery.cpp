//   https://leetcode.com/contest/biweekly-contest-37/problems/fancy-sequence/
const int nax = 1e5+5, mod = 1e9+7;
vector<int>mul,add,arr;

#define tm1 ((tl+tr)>>1)
#define tm2 (tm1+1)
void push(int rt){
    (add[rt<<1|0]*=mul[rt])%=mod;
    (add[rt<<1|1]*=mul[rt])%=mod;
    (add[rt<<1|0]+=add[rt])%=mod;
    (add[rt<<1|1]+=add[rt])%=mod;
    (mul[rt<<1|0]*=mul[rt])%=mod;
    (mul[rt<<1|1]*=mul[rt])%=mod;
    add[rt] = 0, mul[rt] = 1;
}
void addUpdate(int rt,int tl,int tr,int l,int r,int val){
    if(l > r )return;
    if( tl == l && tr == r ){
        (add[rt]+=val)%=mod;
        return;
    }
    push(rt);
    addUpdate(rt<<1|0,tl,tm1,l,min(r,tm1),val), addUpdate(rt<<1|1,tm2,tr,max(l,tm2),r,val);
}
void mulUpdate(int rt,int tl,int tr,int l,int r,int val){
    if( l > r )return;
    if( tl == l && tr == r ){
        (add[rt]*=val)%=mod, (mul[rt]*=val)%=mod;
        return;
    }
    push(rt);
    mulUpdate(rt<<1|0,tl,tm1,l,min(r,tm1),val), mulUpdate(rt<<1|1,tm2,tr,max(l,tm2),r,val);
}
int query(int rt,int tl,int tr,int pos){
    if( tl == tr ){
        return (arr[tl]*mul[rt]%mod + add[rt])%mod;
    }
    push(rt);
    if( pos <= tm1 )return query(rt<<1|0,tl,tm1,pos);
    return query(rt<<1|1,tm2,tr,pos);
}
