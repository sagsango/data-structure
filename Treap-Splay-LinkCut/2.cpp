//Building a Treap in O(N) in offline mode
//Given a sorted list of keys, it is possible to construct atreap faster than
//by inserting the keys one at a time which takes O(N log N ). Since the keys
//are sorted, a balanced binary search tree can be easily constructed in linear
//time. The heap values Y are initialized randomly and then can be heapified 
//independent of the keys X to build the heap in O(N).

void heapify (pitem t) { 
	if (!t) return;
	pitem max = t;
	if (t->l != NULL && t->l->prior > max->prior)
		max = t->l;
	if (t->r != NULL && t->r->prior > max->prior)
		max = t->r; 
	if (max != t) {
		swap (t->prior, max->prior);
		heapify (max);
	} 
}
pitem build (int * a, int n) {
	// Construct a treap on values {a[0], a[1], ..., a[n - 1]} if (n == 0) return NULL;
	int mid = n / 2;
	pitem t = new item (a[mid], rand ());
	t->l = build (a, mid);
	t->r = build (a + mid + 1, n - mid - 1);
	heapify (t);
	upd_cnt(t); // Note: calling upd_cnt(t) is only necessary if you need the subtree sizes.
	return t;
}
