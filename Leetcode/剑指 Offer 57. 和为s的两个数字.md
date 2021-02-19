#### 题意

在一个有序数组里找两个和为s的数字

#### 思路

- 1⃣️有序，立刻联想到二分查找，我们可以依次遍历数组中的每个数字，然后二分查找另一个数字使得和可以为s。
- 2⃣️双指针的写法
  - 一开始分别放在最左和最右，对应为最小和最大的数字，记两个指针指向的元素的和为`sum`
  - 如果`sum > target`，说明太大，则右边的指针应该往左走
  - 如果`sum < targe`t，说明太小，则左边的指针应该往右走

#### 代码（二分查找）

```c++
class Solution {
public:
    int find_pair(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] > target) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto n: nums) {
            int p = find_pair(nums, target - n);
            if(p != -1) {
                return {n, nums[p]};
            }
        }
        return {};
    }
};
```

#### 代码（双指针法）

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int cur1 = 0, cur2 = nums.size() - 1;
        while(cur1 != cur2) {
            int sum = nums[cur1] + nums[cur2];
            if(sum == target) {
                return {nums[cur1], nums[cur2]};
            }else if(sum > target) {
                cur2--;
            }else {
                cur1++;
            }
        }
        return {};
    }
};
```

