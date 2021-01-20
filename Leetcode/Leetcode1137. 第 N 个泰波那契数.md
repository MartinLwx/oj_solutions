#### 题意

如题意所示，类似求斐波那契数列

#### 思路

- 题目已经限制了范围，保证了可以用`int`来表示
- 注意不要采用递归算法，因为递归中存在大量的重复计算，比如`tib(4) = tib(3) + tib(2) + tib(1)`和`tib(5) = tib(4) + tib(3) + tib(2)`，两个都要计算`tib(3)`，后面的情况类似，**有大量重复计算效率低**。实际上测试的话，**在`n = 34`的时候就会超出时间限制了**

#### 代码

```c++
class Solution {
public:
    int tribonacci(int n) {
        vector<int> tib(38);
        tib[0] = 0;
        tib[1] = 1;
        tib[2] = 1;
        for(int i=3;i<=37;i++) {
            tib[i] = tib[i - 1] + tib[i - 2] + tib[i - 3];
        }
        return tib[n];
    }
};
```

