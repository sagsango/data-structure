Tutoril              :    https://cp-algorithms.com/data_structures/fenwick.html
Practice Problem     :    https://codeforces.com/gym/259774/problem/A

class RangeBIT{
	/**
	 * Function : update Range [l ,r ] by +val
	 * get final addentent at ith index 
	 * O(logn) Range updation
	 * O(logn) Get Addentnd
	 **/
	private :vector<int>v;
	private :int N;
	public:
	RangeBIT(int N)
	{
		v=vector<int>(N+2);
		this->N=N;
	}
	void update(int I,int val)
	{
		while(I<=N){v[I]+=val;I+=I&-I;}
	}
	int sum(int I)
	{
		int s=0;while(I>0){s+=v[I];I-=I&-I;}return s;
	}
	void range_update(int l,int r,int val)
	{
		update(l+0,+val);
		update(r+1,-val);
	}
	int get_addented(int I)
	{
		return sum(I);
	}
};

int32_t main()
{
	IOS
	RangeBIT b(1e6);
	b.range_update(1,5,2);
	b.range_update(4,5,3);
	for(int i=1;i<=5;i++)
	cout<<i<<" "<<b.get_addented(i)<<endl;
	
	
}
