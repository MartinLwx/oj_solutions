#### 题意

就是计算[1..n]范围内，每个数字的数位和，然后数位和一样的分到同一组，最后看并列最多的组有多少个

#### 思路

- 计算数位和只要不断`%10`就好了
- 使用`map<int,int>`就可以很方便的将数位和一样的进行计数

#### 代码

```c++
class Solution {
public:
    int cal(int n) {
        int sum = 0;
        while(n) {
            int t = n % 10;
            sum += t;
            n /= 10;
        }
        return sum;
    }   //计算数位和

    int countLargestGroup(int n) {
        map<int, int> hash;
        for(int i=1;i<=n;i++) {
            int sum = cal(i);
            hash[sum]++;
        }
        //看并列最多的组里的元素有几个
        int max_cnt = -1;
        for(auto it: hash) {
            if(it.second > max_cnt) {
                max_cnt = it.second;
            }
        }
        //看并列最多的组有几个
        int ans = 0;
        for(auto it: hash) {
            if(it.second == max_cnt) {
                ans++;
            }
        }
        return ans;
    }
};
```

