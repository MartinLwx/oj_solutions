#### 题意

把字符串前面的若干个字符转移到字符串的尾部，要求只用一个函数实现

#### 思路

- 利用线性代数中的矩阵求逆的思想：$(AB)^{-1} = B^{-1}A^{-1}$

- 定义一个函数`reverse(s, l, r)`，将字符串`s`的`[l, r]`区间内的元素逆置，比如`abc`变为`cba`，这个`reverse()`函数可以自己写或者用STL里的
- 以题目为例，`abcdefg->gfedcba`分下面几步
  - 整体逆置：`gfedcba`
  - 逆置前5位：`cdefgba`，5 = 字符串长度 - 2
  - 逆置后2位：`cdefgab`，题目说要左旋转2位
  - 当左旋转的位数 > 字符串的长度的时候，要用%操作

#### 代码

```c++
class Solution {
public:
    void rever(string& s, int l, int r) {
        for(int i = l; i <= (l + r) / 2; i++) {
            swap(s[i], s[l + r - i]);
        }
    }
    string reverseLeftWords(string s, int n) {
        n = n % (s.size() + 1);
        rever(s, 0, s.size() - 1);
        rever(s, 0, s.size() - n - 1);
        rever(s, s.size() - n, s.size() - 1);
        return s;
    }
};
```

