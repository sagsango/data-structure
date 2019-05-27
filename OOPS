#include<bits/stdc++.h>
using namespace std;
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
		
