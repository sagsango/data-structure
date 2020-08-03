template<class type>
class minqueue{
	private:
	stack<pair<type,type>>st1,st2;
	public:
	bool size()  { 	return st1.size() + st2.size();		 }
	bool empty() {	return st1.empty() & st2.empty();	 }
	type pop(){
		if( st2.empty() ){
			while( !st1.empty() ){
				type  x = st1.top().first; st1.pop();
				type  mn = st2.empty() ? x : x  < st2.top().second ? x : st2.top().second;
				st2.push({x,mn});
			}
		}
		type  x = st2.top().first; st2.pop();
		return x;
	}
	void push(type x){
		type  mn = st1.empty() ? x : x < st1.top().second ? x : st1.top().second;
		st1.push({x,mn});
	}
	type min(){
		if( st1.empty() ) return st2.top().second;
		if( st2.empty() ) return st1.top().second;
		type  x = st1.top().second < st2.top().second ? st1.top().second : st2.top().second;
		return x;
	}
};
