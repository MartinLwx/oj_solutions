#### 题意

将数组中的所有奇数移动到偶数前面

#### 思路

- 可以借鉴快排的思想，快排每一次划分都会确定一个元素的最终位置。在快排中，我们是每次把比「枢轴」小的放左边，比「枢轴」大的放右边，类比于这个，我们可以把相对于「枢轴」来说是奇数的移动到左边，相对于「枢轴」来说是偶数的放右边。一次划分过后就完成了调换的过程。代码也是在快排的模板上改的。

#### 代码

```c++
class Solution {
public:
    void partition(vector<int>& nums, int l, int r) {
        int tmp = nums[l];
        while(l < r) {
						//相对于快排做的改动的是&&之后的判断
            while(l < r && (nums[r] & 1) == 0)     r--;
            nums[l] = nums[r];
            while(l < r && (nums[l] & 1) == 1)     l++;
            nums[r] = nums[l];
        }
        nums[l] = tmp;
    }

    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        partition(nums, 0, nums.size() - 1);
        return nums;
    }
};
```

