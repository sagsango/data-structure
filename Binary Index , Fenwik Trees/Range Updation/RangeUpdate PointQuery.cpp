Tutoril              :    https://cp-algorithms.com/data_structures/fenwick.html
Practice Problem     :    https://codeforces.com/gym/259774/problem/A

class RangeBIT{
	/**
	 * Function : Range add [l ,r ] by +val
	 *            get final value at ith index 
	 * O(logn) Range add
	 * O(logn) Get final value 
	 **/
	private :vector<int>v;
	         int N;
	public:
	RangeBIT(int N=1e6)
	{
		v=vector<int>(N+2);
		this->N=N;
	}
	private:
	void add(int I,int val)
	{
		while(I<=N){v[I]+=val;I+=I&-I;}
	}
	int sum(int I)
	{
		int s=0;while(I>0){s+=v[I];I-=I&-I;}return s;
	}
	public:
	void range_add(int l,int r,int val)  // Note use rage_add(point,point,val) : for point updation
	{
		add(l+0,+val);
		add(r+1,-val);
	}
	int value(int I)
	{
		return sum(I);
	}
};

int32_t main()
{
	IOS
	RangeBIT b(1e6);
	b.range_add(1,5,2);
	b.range_add(4,5,3);
	for(int i=1;i<=5;i++)
	cout<<i<<" "<<b.value(i)<<endl;
	
	
}
