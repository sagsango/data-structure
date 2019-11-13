class BIT{
	/**
	 * Function : add ith index by val
	 *            get pefix_sum upto ith index
	 *            get range_sum from  l to r
	 * O(logn) add at ith index 
	 * O(logn) Range sum
	 * O(logn) prefix_sum
	 **/
	private :vector<int>B;
	         int N;
	public:
	BIT(int N=1e6)
	{
		B=vector<int>(N+1);
		this->N=N;
	}
	private:
	int sum(int I)
	{
		int s=0;while(I>0){s+=B[I];I-=I&-I;}return s;
	}
	public:
	void add(int I,int val)
	{
		while(I<=N){B[I]+=val;I+=I&-I;}
	}
	int prefix_sum(int I)
	{
		return sum(I);
	}
	int range_sum(int l,int r)
	{
		return sum(r)-sum(l-1);
	}
};
