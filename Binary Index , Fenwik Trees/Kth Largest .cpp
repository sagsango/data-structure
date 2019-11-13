class OrderedTree {
    private:int *bit = new int[1000001];
    private:int length=1000000LL;
    private: void update(int n, int idx, int x) {
        while (idx <= n) {
            bit[idx] += x;
            idx += idx & -idx;
        }
    }
    private: int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    public:
    void insert(int x) {
        update(length, x, 1);
    }
    void remove(int x) {
        update(length, x, -1);
    }
    int findRank(int x) {
        return getSum(x);
    }
    int getKthSmallest(int k) {
        int l = 0, h = length - 1, result = -1;
        while (l <= h) {
            int mid = l + ((h - l) >> 1);
            int sum = getSum(mid);
            if (sum >= k) {
                result = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return result;
    }
};

OrderedTree T;
