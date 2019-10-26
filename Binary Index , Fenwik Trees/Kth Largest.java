import java.io.*;

class OrderedTree {
    private int[] bit = new int[1000001];
    private void update(int n, int idx, int x) {
        while (idx <= n) {
            bit[idx] += x;
            idx += idx & -idx;
        }
    }
    private int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    void insert(int x) {
        update(bit.length-1, x, 1);
    }
    void delete(int x) {
        update(bit.length-1, x, -1);
    }
    int findRank(int x) {
        return getSum(x);
    }
    int getKthSmallest(int k) {
        int l = 0, h = bit.length - 1, result = -1;
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
}

class GFG{
    private static int getKthSmallest(String[] a, int k) {
        OrderedTree tree = new OrderedTree();
        for (String i : a) tree.insert(Integer.parseInt(i));
        return tree.getKthSmallest(k);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t > 0) {
            br.readLine();
            String[] a = br.readLine().trim().split(" ");
            int k = Integer.parseInt(br.readLine().trim());
            System.out.println(getKthSmallest(a, k));
            t -= 1;
        }
    }
}
