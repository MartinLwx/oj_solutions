#### 题意

计算动态和，也就是前缀和

#### 思路

- 其实这就是数组相关的算法题常用的思想，利用前缀和数组来查询区间和，相当高效

#### 代码

```c++
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<int> sum;
        sum.emplace_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            sum.emplace_back(nums[i] + sum[i - 1]);
        }
        return sum;
    }
};
```

