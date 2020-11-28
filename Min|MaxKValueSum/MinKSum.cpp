//       https://codeforces.com/gym/263370/problem/E
template<class type>
class minKSum{
	private:
	multiset<type>sl,sr;
	int k;
	type s;
	public:
	minKSum(int k){
		this->k = k;
		s = 0;
	}
	int size(){
		return sl.size() + sr.size();
	}
	void insert(type x){
		sl.insert(x), s += x;
		if( (int)sl.size() > k ){
			x = *sl.rbegin();
			s -= x;
			sr.insert(x);
			sl.erase(sl.find(x));
		}
	}
	void remove(type x){
		if( sr.find(x) != sr.end() ){
			sr.erase(sr.find(x));
		}else{
			s -= x;
			sl.erase(sl.find(x));
			if( sr.size() ){
				x = *sr.begin();
				s += x;
				sr.erase(sr.begin());
				sl.insert(x);
			}
		}
	}
	type sum(){
		if( sl.size() != k )
			bug3(sl.size(), sl.size() + sr.size(),k );
			
		assert( (int)sl.size() == k );
		return s;
	}
};
