#### 题意

简单来说就是二维矩阵，要对每一行矩阵求和（资产总量），然后找最大的行（客户）即可

#### 思路

- 简答的题目，逐次遍历求和找最大即可

#### 代码

```c++
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_value = -1;
        for(auto row: accounts) {
            int row_sum = accumulate(row.begin(), row.end(), 0);
            max_value = max(max_value, row_sum);
        }
        return max_value;
    }
};
```

