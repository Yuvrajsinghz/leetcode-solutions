// Problem: Longest Substring of One Repeating Character
// Difficulty: Hard
// Approach: Segment Tree
// Time Complexity: O((n + q) log n)
// Space Complexity: O(n)

class Solution {
public:
    struct Node {
        int len;
        int prefLen, suffLen, best;
        char prefChar, suffChar;

        Node()
            : len(0), prefLen(0), suffLen(0), best(0),
              prefChar(0), suffChar(0) {}

        Node(char c)
            : len(1), prefLen(1), suffLen(1), best(1),
              prefChar(c), suffChar(c) {}
    };

    vector<Node> seg;

    Node merge(Node left, Node right) {
        if (left.len == 0)
            return right;

        if (right.len == 0)
            return left;

        Node res;

        res.len = left.len + right.len;

        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        res.prefLen = left.prefLen;

        if (left.prefLen == left.len &&
            left.suffChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }

        res.suffLen = right.suffLen;

        if (right.suffLen == right.len &&
            left.suffChar == right.prefChar) {
            res.suffLen += left.suffLen;
        }

        res.best = max(left.best, right.best);

        if (left.suffChar == right.prefChar) {
            res.best = max(
                res.best,
                left.suffLen + right.prefLen
            );
        }

        return res;
    }

    void build(int idx, int l, int r, string& s) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[idx] = Node(ch);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
