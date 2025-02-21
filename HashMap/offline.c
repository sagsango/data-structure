//Tested here:  https://leetcode.com/problems/unique-number-of-occurrences/submissions/1551127889/?envType=study-plan-v2&envId=leetcode-75

enum hash_id {FIRST, SECOND, THIRD, INVALID};

struct value {
    int num;
    enum hash_id id;
};
char cmp(struct value * a, struct value * b) {
    return a->num == b->num && a->id == b->id;
}

struct node {
    struct value * val;
    int cnt;
    struct node * next;
};

struct node *htable[1<<4][1<<4][1<<4][1<<4];

#define UNIT_MASK ((1<<4)-1)
const int mask_start[4] = {0, 8, 16, 24};
#define ID(i) (val->num >> mask_start[i] & UNIT_MASK)

//#define debug(x) printf(#x " val:%d, cnt:%d\n", x->val, x->cnt);

struct node * h_search(struct value * val) {
    struct node *node = htable[ID(0)][ID(1)][ID(2)][ID(3)];
    while (node) {
        if (cmp(node->val, val)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

bool h_insert (struct value *  val) {
    struct node * node;
    if (node = h_search(val)) {
        node->cnt += 1;
        free(val);
        //debug(node);
        return true;
    }

    node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->cnt = 1;
    node->next = NULL;
    //debug(node);

    struct node **head = &htable[ID(0)][ID(1)][ID(2)][ID(3)];

    if (*head == NULL) {
        *head = node;
        //debug(search(val));
        return false;
    }
    node->next = *head;
    *head = node;
    //debug(search(val));
    return false;
}

void h_remove (struct value * val, char all) {
    struct node * node;
    if ((node = h_search(val)) && node->cnt) {
        if (all) {
            node->cnt = 0;
        }else {
            node->cnt -= 1;
        }
    }
}

void h_erase() {
    for (int i=0; i<1<<4; ++i) {
        for (int j=0; j<1<<4; ++j) {
            for (int k=0; k<1<<4; ++k) {
                for (int l=0; l<1<<4; ++l) {
                    struct node *node = htable[i][j][k][l];
                    while (node) {
                        struct node * next = node->next;
                        free(node->val);
                        free(node);
                        node = next;
                    }
                    htable[i][j][k][l] = 0;
                }
            }
        }
    }
}

