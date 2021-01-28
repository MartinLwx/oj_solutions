#### 题意

请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。

#### 思路

- 一开始理解错题意了，题目的意思是说要去掉的是主对角线和副对角线的交界点（最中间的元素，也就是矩阵的边长为奇数的时候才会有交界点）。
- 而我以为是在副对角线中的元素如果在主对角线出现过就不计入总和。
- 按照正确的理解就很简单啦，直接算就好了。

#### 代码

```c++
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len = mat.size();
        int ans = 0;
        for(int i=0;i<len;i++) {
            ans += mat[i][i];
        }//计算主对角线
        for(int i=0;i<len;i++) {
            ans += mat[i][len - i - 1];
        }//计算副对角线
        if(len & 1) {
            ans -= mat[len / 2][len / 2];
        }//如果边长为奇数，去掉其交界点
        return ans;
    }
};
```

