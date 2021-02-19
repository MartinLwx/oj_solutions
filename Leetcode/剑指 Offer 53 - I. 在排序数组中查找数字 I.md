#### 题意

统计一个数字在排序数组中的出现次数

#### 思路

- 1️⃣设置哈希表来记住每个数字的出现个数，最后检查即可。**但是这个没有利用题目说的数组本身已经有序这个特点。**
- 2️⃣其实数组是排序好的这个关键信息是很好的提示——使用二分来确定这个数字的索引上下界，最后相减就知道一共有几个了

#### 代码（哈希表）

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for(auto num: nums) {
            table[num]++;
        }
        if(table.count(target) == 0) {
            return 0;
        }else {
            return table[target];
        }
        return table[target];
    }
};
```

#### 代码（二分）

```c++
class Solution {
public:
    int find_low(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        if(nums[left] == target) {
            return left;
        }else {
            return -1;
        }
    }//二分找下界
    int find_high(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) + 1 / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            }else {
                left = mid;
            }
        }
        if(nums[left] == target) {
            return left;
        }else {
            return -1;
        }
    }//二分找上界
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        int cur1 = find_low(nums, target);
        int cur2 = find_high(nums, target);
        if(cur1 == -1) {
            return 0;
        }else {
            return cur2 - cur1 + 1;
        }
        return -1;
    }
};
```

