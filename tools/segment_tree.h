#include <vector>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void updateRange(int left, int right, int value) {
        updateRange(1, 0, n - 1, left, right, value);
    }

    int query(int left, int right, const std::string& queryType) {
        if (queryType == "min") {
            return queryMin(1, 0, n - 1, left, right);
        } else if (queryType == "max") {
            return queryMax(1, 0, n - 1, left, right);
        } else if (queryType == "sum") {
            return querySum(1, 0, n - 1, left, right);
        } else {
            // Handle unsupported query type
            return 0;
        }
    }

private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateRange(int node, int start, int end, int left, int right, int value) {
        if (left > end || right < start) {
            // Range is completely outside the current node
            return;
        }
        if (left <= start && right >= end) {
            // Range is completely inside the current node
            tree[node] += (end - start + 1) * value;
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, left, right, value);
        updateRange(2 * node + 1, mid + 1, end, left, right, value);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryMin(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            // Return a large value to indicate that the range is invalid
            return INT_MAX;
        }
        if (left <= start && right >= end) {
            // Return the value stored in the current node
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryMin(2 * node, start, mid, left, right);
        int rightMin = queryMin(2 * node + 1, mid + 1, end, left, right);
        return std::min(leftMin, rightMin);
    }

    int queryMax(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            // Return a small value to indicate that the range is invalid
            return INT_MIN;
        }
        if (left <= start && right >= end) {
            // Return the value stored in the current node
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryMax(2 * node, start, mid, left, right);
        int rightMax = queryMax(2 * node + 1, mid + 1, end, left, right);
        return std::max(leftMax, rightMax);
    }

    int querySum(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            // Return 0 to indicate that the range is invalid
            return 0;
        }
        if (left <= start && right >= end) {
            // Return the value stored in the current node
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = querySum(2 * node, start, mid, left, right);
        int rightSum = querySum(2 * node + 1, mid + 1, end, left, right);
        return leftSum + rightSum;
    }
};