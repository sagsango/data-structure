// Tested on: https://leetcode.com/problems/number-of-recent-calls/submissions/1551672755/?envType=study-plan-v2&envId=leetcode-75

#define Q_SIZE 10010
struct queue{
    int to_read, to_write, cnt;
    int arr[Q_SIZE];
    int (*size)(struct queue*);
    int (*full)(struct queue*);
    int (*empty)(struct queue*);
    int (*push)(struct queue*, int);
    int (*pop)(struct queue*);
    int (*top)(struct queue*);

} queue;
int q_full(struct queue *q) {
    return (q->to_write + 1)%Q_SIZE == q->to_read;
}
int q_empty(struct queue *q) {
    return q->to_write == q->to_read;
}
int q_size(struct queue *q) {
    return q->cnt;
}
int q_push(struct queue *q, int val) {
    assert (!q->full(q));
    q->cnt += 1;
    q->arr[q->to_write] = val;
    q->to_write = (q->to_write+1)%Q_SIZE;
    return 0;
}
int q_pop(struct queue *q) {
    assert(!q->empty(q));
    q->cnt -= 1;
    q->to_read = (q->to_read+1)%Q_SIZE;
    return 0;
}
int q_top(struct queue *q) {
    assert(!q->empty(q));
    return q->arr[q->to_read];
}
struct queue * new_q() {
    struct queue * q = (struct queue*) malloc(sizeof(struct queue));
    q->to_read = q->to_write = q->cnt = 0;
    q->size = q_size;
    q->full = q_full;
    q->empty = q_empty;
    q->push = q_push;
    q->pop = q_pop;
    q->top = q_top;
    return q;
}
int delete_q(struct queue **q) {
    assert(*q);
    free(*q);
    *q = 0;
    return 0;
}
/* How to use */
int main() {
  struct queue * q = new_q();
  q->push(q, 1);
  int front = q->top(q);
  q->pop(q);
  int is_empty = q->empty(q);
  int is_full = q->full(q);
  int size = q->size(q);
}
