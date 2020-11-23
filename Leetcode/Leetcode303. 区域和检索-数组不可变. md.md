#### 题意

给定一个整数数组  *nums*，求出数组从索引 *i* 到 *j* (*i* ≤ *j*) 范围内元素的总和，包含 *i, j* 两点。

#### 思路

- 如果是暴力法，每次查询的时候都要遍历`i-->j`，进行求和，复杂度是$O(n)$。题目明确说了会多次调用，所以这个暴力法是会超时的
- 引入前缀和的思想，用`sum[i]`表示`[0..i-1]`的区间和，那么`[i, j]`的区间和就是`sum[j+1] - sum[i]`，先求出前缀和数组用时$O(n)$，后面每次查询的操作都是$O(1)$

#### 代码

```c++
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1, 0);
        for(int i=0;i<nums.size();i++)
            sum[i + 1] = sum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};
```

