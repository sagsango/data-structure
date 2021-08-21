#Tested
Tutoril              :    https://cp-algorithms.com/data_structures/fenwick.html
Practice Problem     :    https://codeforces.com/gym/259774/problem/A
                     :    https://codeforces.com/gym/262913/submission/68431073

class RangeBIT{
	/**
	 * Function : update Range [l ,r ] by +val
	 *            get pefix_sum upto ith index
	 *            get range_sum from  l to r
	 * O(logn) Range updation
	 * O(logn) Range sum
	 * O(logn) prefix_sum
	 **/
	private :vector<int>B[2];
	         int N;
	public:
	RangeBIT(int N=1e6)
	{
		B[0]=vector<int>(N+2);
		B[1]=vector<int>(N+2);
		this->N=N;
	}
	private:
	void add(vector<int>&B,int I,int val)
	{
		while(I<=N){B[I]+=val;I+=I&-I;}
	}
	int sum(vector<int>&B,int I)
	{
		int s=0;while(I>0){s+=B[I];I-=I&-I;}return s;
	}
	public:
	void range_add(int l,int r,int val)
	{
		add(B[0],l,val);
		add(B[0],r+1,-val);
		add(B[1],l,val*(l-1));
		add(B[1],r+1,-val*r);
	}
	int prefix_sum(int I)
	{
		return sum(B[0],I)*I-sum(B[1],I);
	}
	int range_sum(int l,int r)
	{
		return prefix_sum(r)-prefix_sum(l-1);
	}
};
