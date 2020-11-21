//   https://leetcode.com/contest/biweekly-contest-37/problems/fancy-sequence/
const int nax = 1e5+5, mod = 1e9+7;
vector<int>mul,add,arr;
int Start,End;

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

class Fancy {
public:
    Fancy() {
        mul = vector<int>(nax<<2,1);
        add = vector<int>(nax<<2,0);
        arr = vector<int>(nax<<0,0);
        Start = 1, End = 0;
    }
    void append(int val) {
        arr[++End] = val;
    }
    
    void addAll(int inc) {
        addUpdate(1,1,1e5,Start,End,inc);
        
    }
    
    void multAll(int m) {
        mulUpdate(1,1,1e5,Start,End,m);
        
    }
    
    int getIndex(int idx) {
        
        ++idx;
        if( idx >= Start && idx <= End )
            return query(1,1,1e5,idx);
        return -1;
        
    }
};

int32_t main(){
	IOS
	Fancy ob;
	int x,y;
	while( cin >> x ){
		if( x == 1 ){
			cin >> y;
			ob.append(y);
		}
		if( x == 2 ){
			cin >> y;
			ob.addAll(y);
		}
		if( x == 3 ){
			cin >> y;
			ob.multAll(y);
		}
		if( x == 4 ){
			cin >> y;
			cout << ob.getIndex(y) << endl;
		}
		if( x < 1 || x > 4 ){
			cout << "Invalid" << endl;
			continue;
		}
		for(int i= Start; i<= End; ++i ){
			bug2(i,ob.getIndex(i-1));
		}
	}
	
}
