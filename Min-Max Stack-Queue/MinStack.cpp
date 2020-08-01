template<class type>
class minstack{
	private:
	stack<pair<type,type>>st;
	public:
	bool size()  { 	return st.size(); 	 }
	bool empty() {	return st.empty();	 }
	type pop(){
		type t = st.top().first; st.pop();
		return t;
	}
	void push(type x){
		type mn = st.empty() ? x :  x < st.top().second ? x : st.top().second;
		st.push({x,mn});
	}
	type min(){
		return st.top().second;
	}
};
