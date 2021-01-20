#### 题意

在数组中找到三个数，使得这三个数字的乘积最大

#### 思路

- 需要注意的就是如果数组有正有负的时候，那么要考虑1⃣️一正两负2⃣️三正或三负这两种情况
- 如果我们将这个数组进行排序，那么显然
  - 1⃣️是最小的两个数和最大的数
  - 2⃣️三正三负都是最大的三分数的乘积

- 由分类讨论结果也可以得到不排序的算法，我们只要设置变量来记住最大的三个数 + 最小的两个数字分类计算结果最后比较就好了

#### 代码（排序）

```c++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int last_three = nums[len - 1] * nums[len - 2] * nums[len - 3];
        if(nums[0] > 0 || nums[len - 1] < 0) {      //全正或全负
            return last_three;
        }else if(nums[0] < 0 && nums[1] < 0 && nums[len - 1] > 0) {     //2负1正
            int t = nums[0] * nums[1] * nums[len - 1];   
            if(t > last_three)      //和最后的三个数字的乘积进行比较
                return t;
            else    
                return last_three;
        }else   return last_three;
        return 0;
    }
};
```

#### 代码（扫描）

```c++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = 1001, min2 = 1001; 
        int max1 = -1001, max2 = -1001, max3 = -1001;   //题目给定了数据范围
        for(auto e: nums) {
            if(e < min1) {       //比最小的min1，min2都还小
                min2 = min1;
                min1 = e;
            }else if(e < min2) {    //比min1大，但是比min2小
                min2 = e;
            }
            
            if(e > max3) {      //比最大的三个数都大
                max1 = max2;
                max2 = max3;
                max3 = e;
            }else if(e > max2) {    //比第2大的数字大，比最大的数小
                max1 = max2;
                max2 = e;
            }else if(e > max1) {    //比第3大的数字大，但是比第2大的数组小
                max1 = e;
            }
        }
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};
```

