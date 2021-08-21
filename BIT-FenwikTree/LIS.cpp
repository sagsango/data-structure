https://codeforces.com/contest/340/submission/61458461

const int N = 200000;
int bit[N+1]={0};
void update(int index,int val){
    while(index<=N){
        bit[index]=max(bit[index],val);
        index+=index&-index;
    }
}
int query(int index){
    int res=0;
    while(index){
        res=max(res,bit[index]);
        index&=index-1;
    }
    return res;
}	
	
int32_t main()
{
	IOS
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		update(x,query(x-1)+1);
	}
	cout<<query(N)<<endl;
}	
 
