#### 题意

斐波那契数列求值。

#### 思路

- 简单的递推问题，可以开数组来计算，或者只用三个变量交替循环，这样空间复杂度就是**O(1)**
- ⚠️如果采用了递归做法，因为有大量的重复计算会让算法变得十分低效。🆚递归-16ms；递推-0ms

#### 代码

```c++
//递推法
class Solution {
public:
    int fib(int N) {
        int pre_pre = 0;
        int pre = 1;
        if(N == 0)  return 0;
        if(N == 1)  return 1;
        int new_val;
        for(int i=2;i<=N;i++)
        {
            new_val = pre_pre + pre;
            pre_pre = pre;
            pre = new_val;
        }
        return new_val;
    }
};

//递归法
class Solution {
public:
    int fib(int N) {
        if(N == 0)  return 0;
        if(N == 1)  return 1;
        return fib(N - 1) + fib(N - 2);
    }
};
```

