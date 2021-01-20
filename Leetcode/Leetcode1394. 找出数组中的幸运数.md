#### 题意

找一个整数数组中，整数出现频次 = 数值大小，称这种数为幸运数，多个的话返回最大的

#### 思路

- 题目已经暗示得很明显了，`1 <= arr[i] <= 500`
- 可以利用桶排的思想，用`frequency[i]`表示i这个整数出现的频次，最后检查`[1, 500]`里的数字就好了

#### 代码

```c++
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> frequency(501, 0);
        for(auto e: arr) {
            frequency[e]++;
        }
        int ans = -1;
        //因为要最大的，所以我们是从后往前找，找到就break
        for(int i=500;i>=1;i--) {
            if(frequency[i] == i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
```

