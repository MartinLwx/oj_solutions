#### 题意

统计小于`n`的非负整数的质数的数量

#### 思路

- 采用素数筛法，因为这里n最多可以达到$5*10^6$，还是相当大的

- 比如`2`是质数，那么`2`的倍数肯定就都不是质数，用这种思想逐个枚举，并且开一个`bool`数组进行标记，那么最后我们就能筛选出所有的质数

#### 代码

```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<int> table;
        if(n < 2)   return 0;
        vector<int> notPrime(n, 0);
        for(int i=2;i<n;i++)
        {
            if(notPrime[i] == 0)
            {
                table.emplace_back(i);
                for(int j=i+i;j<n;j+=i)   //这里不要写成j<=n
                    notPrime[j] = 1;
            }
        }
        return table.size();
    }
};
```

