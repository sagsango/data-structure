// emaxx.pdf -> 8.5. Treap (Cartesian tree) page.185

#include <iostream>
#include <memory>

using namespace std;

struct item {
	int key, prior;
	item * l, * r;
	item() { }
	item (int key, int prior=0) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;
pitem t;


//Split (T, X) separates tree T in 2 subtrees L and R trees 
//(which are the return values of split) so that L contains 
//all elements with key XL < X, and R contains all elements 
//with key XR > X. This operation has O(log N) complexity 
//and is implemented using an obvious recursion.
void split (pitem t, int key, pitem & l, pitem & r) { 
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
}


//Merge (T1, T2) combines two subtrees T1 and T2 and returns
//the new tree. This operation also has O(logN) complexity. 
//It works under the assumption that T1 and T2 are ordered
//(all keys X in T1 are smaller than keys in T2). Thus, we 
//need to combine these trees without violating the order of priorities Y
void merge (pitem & t, pitem l, pitem r) { 
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
}


//Insert(X,Y) in O(logN).Adds a new node to the tree. One 
//possible variant is to pass only X and generate Y randomly
//inside the operation (while ensuring that it’s different 
//from all other priorities in the tree)
void insert (pitem & t, pitem it) { 
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r),  t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
}

//Erase (X) in O(logN). Looks for a node with the specified 
//key value X and removes it from the tree.
void erase (pitem & t, int key) { 
	if (t->key == key) {
		pitem th = t;
		merge (t, t->l, t->r); 
		delete th;
	}
	else
		erase (key < t->key ? t->l : t->r, key);
}

//Union (T1, T2) in O(M log(N/M)).Merges two trees, assuming 
//that all the elements are different. It is possible to achieve
//the same complexity if duplicate elements should be removed during merge.
pitem unite (pitem l, pitem r) { 
	if(!l||!r) 
		return l?l:r;
	if (l->prior < r->prior) 
		swap (l, r); 
	pitem lt, rt;
	split (r, l->key, lt, rt);
	l->l = unite (l->l, lt);
	l->r = unite (l->r, rt);
	return l; 
}

int main(){

}

