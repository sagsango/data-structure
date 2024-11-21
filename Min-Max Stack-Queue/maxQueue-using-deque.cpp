// submission link: https://leetcode.com/problems/sliding-window-maximum/


struct maxQueue {
    deque<pair<int, int>> q; // we maintain decreasing order
    int _size;
    maxQueue() {
        _size = 0;
    }
    void push(int num) {
        int inFront = 0;
        while (!q.empty() && q.back().first < num) {
            inFront += q.back().second + 1; // previous_deletions + curent_deletions
            q.pop_back();
        }
        q.push_back({num, inFront});
        _size += 1;
    }

    int max() {
        return q.front().first;
    }

    void pop() {
        int num = q.front().first;
        int inFront = q.front().second;
        q.pop_front();
        if (inFront) {
            inFront -= 1;
            q.push_front({num, inFront});
        }
        _size -= 1;
    }

    int size() {
        return _size;
    }
};
