
// https://cses.fi/problemset/result/505201/
// type 0: Update
// type 1: Add
// type 2: Nothing
const int maxn = 2e5+10;
vector<int>t(maxn<<2),lazy(maxn<<2),type(maxn<<2,2),a(maxn);
int n,m;
void push(int rt,int l,int r){
	if( type[rt] == 2 )return;
	int m = (l+r)>>1;
	if( type[rt] ){
		t[rt<<1]+=lazy[rt]*(m-l+1);
		lazy[rt<<1]+=lazy[rt];
		t[(rt<<1)+1]+=lazy[rt]*(r-m);
		lazy[(rt<<1)+1]+=lazy[rt];
	}
	else{
		t[rt<<1]=lazy[rt]*(m-l+1);
		lazy[rt<<1]=lazy[rt];
		t[(rt<<1)+1]=lazy[rt]*(r-m);
		lazy[(rt<<1)+1]=lazy[rt];
	}
	type[rt<<1]=min(type[rt<<1],type[rt]);
	type[(rt<<1)+1]=min(type[(rt<<1)+1],type[rt]);
	lazy[rt]=0;
	type[rt]=2;
}
void built(int rt,int l,int r){
	if(l==r){t[rt]=a[l];return;}
	built(rt<<1,l,(l+r)>>1);
	built((rt<<1)+1,((l+r)>>1)+1,r);
	t[rt]=t[rt<<1]+t[(rt<<1)+1];
}
void update(int rt,int tl,int tr,int l,int r,int qt,int val){
	if(l>r)return;
	if(tl==l&&tr==r){
		if(qt){
			t[rt]+=val*(tr-tl+1);
			lazy[rt]+=val;
		}else{
			t[rt]=val*(tr-tl+1);
			lazy[rt]=val;
		}
		type[rt]=min(type[rt],qt);
		return;
	}
	push(rt,tl,tr);
	update(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),qt,val);
	update((rt<<1)+1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,qt,val);
	t[rt]=t[rt<<1]+t[(rt<<1)+1];
}
int query(int rt,int tl,int tr,int l,int r){
	if(l>r)return 0;
	if(tl==l&&tr==r)return t[rt];
	push(rt,tl,tr);
	int ans = query(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1))+query((rt<<1)+1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r);
	t[rt]=t[rt<<1]+t[(rt<<1)+1];
	return ans;
}
 
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	built(1,1,n);
	for(int i=1;i<=m;i++){
		int qt;cin>>qt;
		if( qt == 1){
			int l,r,dx;cin>>l>>r>>dx;
			update(1,1,n,l,r,1,dx);
		}else if(qt==2){
			int l,r,x;cin>>l>>r>>x;
			update(1,1,n,l,r,0,x);
		}else{
			int l,r;cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	
}
