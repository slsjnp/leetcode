// 2022-06-06 18:31:48
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    vector<int> lineTree;
    int _size;

    NumArray(vector<int> &nums) {
        _size = nums.size();
        lineTree = vector<int>(_size * 4);
        buildTree(nums, lineTree, 0, nums.size() - 1, 1);
    }

    void buildTree(vector<int> const &arr, vector<int> &tree, int start, int end, int node_idx) {
        if (start == end) {
            tree[node_idx] = arr[start];
        } else {
            int left_node = 2 * node_idx;
            int right_node = 2 * node_idx + 1;
            int mid = start + (end - start) / 2;
            buildTree(arr, tree, start, mid, left_node);
            buildTree(arr, tree, mid + 1, end, right_node);
            tree[node_idx] = tree[left_node] + tree[right_node];
        }
    }

    void update(int index, int val) {
        // updateTree(lineTree, 0, _size - 1, 1, index, val);
        int node = 1;
        int l = 0;
        int r = _size - 1;
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if (index == mid && l == r){
                break;
            }
            else if (index <= mid){
                r = mid;
                node *= 2;
            }
            else if (index > mid){
                l = mid + 1;
                node *= 2;
                ++node;
            }
        }
        index = node;
        // printf("%d %d %d \n", index, lineTree[index], val);
        if (index < lineTree.size()) {
            int diff = val - lineTree[index];
            lineTree[index] = val;
            while (index > 1) {
                index /= 2;
                lineTree[index] += diff;
            }
        } else {
            return;
        }
        // printf("%d %d\n", lineTree[index], val);
    }
    void updateTree(vector<int> &tree, int start, int end, int node_idx, int index, int val){
        if (start == end){
            tree[node_idx] = val;
        } else{
            int left_node = node_idx * 2;
            int right_node = left_node + 1;
            int mid = start + (end - start) / 2;
            if (index > mid){
                updateTree(tree, mid + 1, end, right_node, index, val);
            } else{
                updateTree(tree, start, mid, left_node, index, val);
            }
            tree[node_idx] = tree[left_node] + tree[right_node];
        }
    }

    int sumRange(int left, int right) {
        return query(lineTree, 0, _size - 1, left, right, 1);
    }

    int query(vector<int> &tree, int start, int end, int l, int r, int node_idx) {
        if (l > end || r < start){
            return 0;
        } else if (l <= start && end <= r){
            return lineTree[node_idx];
        } else{
            int left_node = 2 * node_idx;
            int right_node = left_node + 1;
            int mid = start + (end - start) / 2;
            int left_sum = query(tree, start, mid, l , r, left_node);
            int right_sum = query( tree, mid + 1, end, l, r, right_node);
            return left_sum + right_sum;
        }

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RangeSumQueryMutable, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().rangeSumQueryMutable(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}