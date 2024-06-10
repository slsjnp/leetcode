// 2022-08-29 18:52:55
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;
    vector<int> arr;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int _size = arr.size();
        if (k == 0) return {};
        if (k == _size ) return arr;
        this->arr = arr;
        qsort(0, _size - 1, k);
        // for (auto it : arr){
        //     printf("%d ", it);
        // }
        // printf("\n");
        return res;
    }
    void qsort(int l, int r, int k){
        if (l >= r){
            return;
        }
        int index = l + rand() % (r - l);
        int tmp = arr[index];
        int end = r;
        swap(arr[l], arr[index]);
        index = l;
        while(l < r){
            while(l < r && arr[r] > tmp) r--;
            if(l < r) arr[l++] = arr[r];
            while (l < r && arr[l] < tmp) l++;
            if(l < r) arr[r--] = arr[l];
        }
        // printf("%d %d\n", l, r);
        // assert(l == r);
        arr[l] = tmp;
        if (l - index == k){
            for (int i = index; i < l; ++i) {
                res.push_back(arr[i]);
            }
            return;
        } else if (l - index < k){
            for (int i = index; i <= l; ++i) {
                res.push_back(arr[i]);
            }
            qsort(l + 1, end, k - (l - index + 1));
        } else{
            qsort(index, l - 1, k);
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZuiXiaoDeKgeShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().zuiXiaoDeKgeShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}