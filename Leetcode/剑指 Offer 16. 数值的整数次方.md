#### 题意

计算`x^n`次方

#### 思路

🍉借鉴快速幂的思想

- 如果$n$是奇数那么$x^n = x * x ^ {n-1}$
- 如果$n$是偶数，那么$x^n = x ^ {n/2} * x ^ {n/2}$

- ⚠️
  - `n & 1 == 1`也就是判断二进制最低位是否为1，等价于判断是不是奇数，用位运算会快点
  - 注意$n$的范围是$-2^{31},2^{31}-1$，如果计算`pow(x, n)`的时候我们是传入`-n`，那么当$n=-2^{31}$的时候$-n=2^{31}$会超过`int`的表示范围，所以这里要转化为`long long`

#### 代码

```c++
class Solution {
public:
    double compute(double x, long long n)
    {
        if(n == 0)  return 1.0;
        if(n & 1)   return x * myPow(x, n - 1);
        else{
            double mul = myPow(x, n / 2);
            return mul * mul;
        }
    }
    double myPow(double x, int n) {
        if(x == 1)  return 1.0;
        long long tmp = n;
        if(n == 0)  return 1.0;
        else if(n > 0)   return compute(x, tmp);
        else return 1 / compute(x, -tmp);
    }
};
```

