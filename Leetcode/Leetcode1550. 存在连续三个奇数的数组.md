#### 题意

如题目描述

#### 思路

- 简单来说就是枚举，判断是否为奇数
- 值得一提的是判断奇数可以用`%2`，或者用更高效的位运算，即`&1`，如果是奇数，那么二进制位最低位一定是`1`，那么`&1 = 1`

#### 代码

```c++
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) {
            return false;
        }
        for(int i=1;i<arr.size()-1;i++) {
            if(arr[i - 1]&1 && arr[i]&1 && arr[i + 1]&1) {
                   return true;
            }
        }
        return false;
    }
};
```

