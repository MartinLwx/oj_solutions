#### 题意

对图片先水平翻转再反转图片

水平翻转：就是改为逆序，比如`[1,0,0]->[0,0,1]`

反转图片：`0->1, 1->0`

#### 思路

- 完全按照题目中所说的进行模拟
  - 对于水平翻转：可以用`reverse()`
  - 对于反转图片，可用
    - 1⃣️`^=1`，因为一个数和自己异或是0，0和1异或刚好是1
    - 2⃣️`=abs(1 - ?)`，利用绝对值`abs`来实现转换

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &row: A) {
            reverse(row.begin(), row.end());
        }
        for(auto &row: A) {
            for(auto &ele: row) {
                ele ^= 1;
            }
        }
        return A;
    }
};
```

