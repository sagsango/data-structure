#include<bits/stdc++.h>
using namespace std;




#####################################################################################################################
template <typename T>
class BIT{
	// binary index tree or fenwik tree
	// index starts from 1 to n
	int *fen, size;
public:
    // allocate memory
	BIT(int n) {
		size = n;
		fen = new T [n+1];
	}
	// free memory
	~BIT() {
		delete [] fen;
	}
    // sum of the prifix till pth position
	T sum(int p) {
		T ans = 0;
	    for(int i = p;i;i -= i & -i)
		ans += fen[i];
	    return ans;
	}
	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int p,T val){
	    for(int i = p;i <= size;i += i & -i)
		fen[i] += val;
    }
    // divide each original frequency by c
	void scaleDown(T c){
        for (int i=1 ; i<=size ; i++) fen[i] /= c;
    }
    // multiply each original frequency by c
    void scaleUp(T c){
        for (int i=1 ; i<=size ; i++) fen[i] *= c;
    }
};


int32_t main()
{
	IOS
	BIT<int>bit(10);
	
	for(int i=1;i<=10;i++)
	{    
		//Taking the array elements
		int x;cin>>x;bit.update(i,x);
	}
	
	// Now perform required updation and sum query
}

#####################################################################################################################
class _stack{        // Class [ Class Name : _stack ]
	private:           // Access Specifier
	int stk[1000]={0}; // Data Member
	int t=-1;
	int s=0;
	public:
	void push(int a){  // Member Fucntion
		stk[++t]=a;s++;
	}
	int top(void){
		return stk[t];
	}
	bool empty(void){
		return s==0;
	}
	int size(){
		return s;
	}
	void pop(){
		t--;s--;
	}
	void print()
	{
		for(int i=0;i<=t;i++)cout<<stk[i]<<" ";
		cout<<endl;
	}
};
int main()
{
	_stack st[3];     // Objects [ Objects Name : st[3] ]
	int id;
	cout<<"Choose id:";
	while(cin>>id)
	{cout<<"Choose option:";
		int c=0,d;cin>>c;
		
		switch(c)
		{
			case 3:
			cout<<st[id].top()<<endl;st[id].print();break;
			case 1:
			cin>>d;
			st[id].push(d);st[id].print();break;
			case 2:st[id].pop();st[id].print();break;
			case 4:cout<<st[id].size()<<endl;st[id].print();
			
		}
		cout<<"Choose id:";
	}
}



