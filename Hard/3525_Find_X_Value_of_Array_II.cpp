// Problem: Find X Value of Array II
// Difficulty: Hard
// Link: LeetCode 3525
// Approach: Segment Tree
// Time Complexity: O((n + q) * log(n) * k)
// Space Complexity: O(n * k)

class Solution {
    struct Node {
        int product;
        int cnt[5];

        Node(int k = 0) {
            product = 1 % k;

            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {
        Node res(k);

        res.product = (left.product * right.product) % k;

        for (int i = 0; i < k; i++) {
            res.cnt[i] = left.cnt[i];

            for (int j = 0; j < k; j++) {
                if ((left.product * j) % k == i) {
                    res.cnt[i] += right.cnt[j];
                }
            }
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int value = nums[l] % k;

            tree[node].product = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) {
            value %= k;

            tree[node].product = value;

            for (int i = 0; i < 5; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        k = K;

        int n = nums.size();

        tree.resize(4 * n + 5, Node(k));

        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto& queryData : queries) {
            int index = queryData[0];
            int value = queryData[1];
            int start = queryData[2];
            int x = queryData[3];

            update(1, 0, n - 1, index, value);

            Node result = query(1, 0, n - 1, start, n - 1);

            answer.push_back(result.cnt[x]);
        }

        return answer;
    }
};